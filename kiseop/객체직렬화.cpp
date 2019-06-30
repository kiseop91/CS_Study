// 2019-6-30 김기섭
// inStream, outStream 예제 파일

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
		free(mBuffer); //예제를 위해 포인터를 복사해서 일단 주석처리.두번해제됨.
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
		//free(mBuffer); // 이 예제에서는 둘중하나는 주석처리해야함.
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
	//서버-클라이언트 구조에서 발신측 
	kiseop seop;
	seop.age = 29;
	cout << "이름을 입력하세요 : ";
	cin >> seop.name;

	OutputStream outStream; //  객체를 직렬화해서 outStream객체에 입력한다.
	seop.Write(outStream);

//=================================================================================//

	//서버- 클라이언트 구조에서 수신측
	char* Buffer = static_cast<char*>(malloc(1470)); // 미리 버퍼를 만들어둔다.
	Buffer = outStream.GetBufferPtr(); // 소켓을 통해 전달되어 받았다고 가정. 버퍼에저장한다.
	InputStream inStream(Buffer, 1470);
	
	kiseop seop2;
	seop2.Read(inStream);
	cout << seop2.name << endl << seop2.age;

	return  0;
}