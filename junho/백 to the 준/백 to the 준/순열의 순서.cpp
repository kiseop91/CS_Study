

#include <iostream>

#include <vector>

using namespace std;



//factorials[i]=i!

long long factorials[21];

vector<int> answer, possible;

int N; //총 갯수

//X가 [0, n-1]의 순열일 때 사전순 번호를 반환한다(0에서 시작)

long long getIndex(const vector<int> &X)

{

	long long result = 1;

	for (int i = 0; i < X.size(); i++)

	{

		int less = 0;

		//X[i+1..] 중 X[i]보다 작은 수를 샌다. 이것이 X 앞에 오는 묶음의 수

		for (int j = i + 1; j < X.size(); j++)

			if (X[j] < X[i])

				less++;

		result += factorials[X.size() - i - 1] * less;

		/*

		예를 들어 1, 2, 3, 4로 이루어진 수열에

		2314가 등장했다면

		2>1이므로 3!

		3>1이므로 2!

		1+8=9번째 숫자

		*/

	}

	return result;

}



void permutation(int cnt, long long skip)

{

	if (cnt == N) //N번 진행했다면 끝

		return;

	int i = 0;

	for (; skip > factorials[N - cnt - 1]; i++)

		skip -= factorials[N - cnt - 1];

	answer.push_back(possible[i]);

	possible.erase(possible.begin() + i); //가능한 숫자에서 방금 삽입한 숫자 삭제

	permutation(cnt + 1, skip);

}



void initialize(void)

{

	factorials[0] = factorials[1] = 1;

	for (int i = 2; i <= 20; i++)

		factorials[i] = i * factorials[i - 1];

}



int main(void)

{

	vector<int> X;

	int sel;



	cin >> N;

	if (N < 1 || N>20)

		exit(-1);



	cin >> sel;

	if (sel != 1 && sel != 2)

		exit(-1);

	initialize();

	switch (sel)

	{

	case 1:

		long long skip;

		cin >> skip;

		for (int i = 1; i <= N; i++)

			possible.push_back(i);

		permutation(0, skip);

		for (int i = 0; i < N; i++)

		{

			cout << answer[i];

			if (i != N - 1)

				cout << " ";

		}

		cout << endl;

		break;

	case 2:

		for (int i = 0; i < N; i++)

		{

			int num;

			cin >> num;

			X.push_back(num);

		}

		cout << getIndex(X) << endl;

		break;

	}

	return 0;

}
