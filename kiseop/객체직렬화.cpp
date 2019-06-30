// 2019-6-30 ��⼷
// inStream, outStream ���� ����

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <thread>
using namespace std;

class OutputStream
{
public:
	OutputStream()
		:mBuffer(nullptr), mHead(0), mCapacity(0)
	{
		mBuffer = static_cast<char*>(malloc(8));
	}
	~OutputStream() { 
		free(mBuffer); //������ ���� �����͸� �����ؼ� �ϴ� �ּ�ó��.�ι�������.
	}
	uint32_t GetLength() const { return mHead; }
	char* GetBufferPtr() const { return mBuffer; }

	void Write(uint32_t inData)
	{
		Write(&inData, sizeof(inData));
	}
	void Write(const void* inData, size_t inByteCount)
	{
		uint32_t resultHead = mHead + static_cast<uint32_t>(inByteCount);
		if (resultHead > mCapacity)
			ReallocBuffer(max(mCapacity * 2, resultHead));
		memcpy(mBuffer + mHead, inData, inByteCount);
		mHead = resultHead;
	}

private:
	void ReallocBuffer(uint32_t length)
	{
		mBuffer = static_cast<char*>(realloc(mBuffer, length));
		mCapacity = length;
	}
	char* mBuffer;
//	shared_ptr<char> mBuffer;
	uint32_t mHead;
	uint32_t mCapacity;

};

class InputStream
{
public:
	InputStream(char* inBuffer, uint32_t inByteCount)
		:mCapacity(inByteCount), mHead(0), mBuffer(inBuffer)
	{
	}
	~InputStream()
	{
		//free(mBuffer); // �� ���������� �����ϳ��� �ּ�ó���ؾ���.
	}
	uint32_t GetRemainingDataSize() const { return mCapacity - mHead; }
	void Read(void* outData)
	{
		Read(outData, sizeof(outData));
	}
	void Read(void* outData, uint32_t inByteCount)
	{
		uint32_t resultHead = mHead + inByteCount;
		std::memcpy(outData, mBuffer + mHead, inByteCount);
		mHead = resultHead;
		//cout << (char*)outData << endl;
	}
private:
	char* mBuffer;
	uint32_t mHead;
	uint32_t mCapacity;
};

class kiseop
{
public:
	char name[30];
	int age;
	void Read(InputStream& inStream)
	{
		inStream.Read(&age,sizeof(age));
		inStream.Read(name,sizeof(name));
	}
	void Write(OutputStream& outStream)
	{
		outStream.Write(&age, sizeof(age));
		outStream.Write(name, sizeof(name));
	}
};

int main()
{
	//����-Ŭ���̾�Ʈ �������� �߽��� 
	kiseop seop;
	seop.age = 29;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> seop.name;

	OutputStream outStream; //  ��ü�� ����ȭ�ؼ� outStream��ü�� �Է��Ѵ�.
	seop.Write(outStream);

//=================================================================================//

	//����- Ŭ���̾�Ʈ �������� ������
	char* Buffer = static_cast<char*>(malloc(1470)); // �̸� ���۸� �����д�.
	Buffer = outStream.GetBufferPtr(); // ������ ���� ���޵Ǿ� �޾Ҵٰ� ����. ���ۿ������Ѵ�.
	InputStream inStream(Buffer, 1470);
	
	kiseop seop2;
	seop2.Read(inStream);
	cout << seop2.name << endl << seop2.age;

	return  0;
}