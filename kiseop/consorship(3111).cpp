
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	deque<char> Lstack; 
	deque<char> Rstack; 

	string A, T;
	cin >> A >> T;

	int L, R;
	L = 0; 
	R = T.size() - 1; 

	while (L <= R) 
	{
		while (L <= R) 
		{
			bool b = false;
			Lstack.push_back(T[L]); 
			L++; 
			if (Lstack.size() >= A.size()) 
			{
				b = true;
				for (int i = 0; i < A.size(); i++) { 
					if (A[i] != Lstack[Lstack.size() - A.size() + i]) {
						b = false;
						break;
					}
				}
			}
			if (b) { 
				for (int i = 0; i < A.size(); i++) Lstack.pop_back();
				break;
			}
		}
		while (L <= R) 
		{
			Rstack.push_front(T[R]);
			R--;
			bool b = false;
			if (Rstack.size() >= A.size())
			{
				b = true;
				for (int i = 0; i < A.size(); i++) {
					if (A[i] != Rstack[i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < A.size(); i++)
					Rstack.pop_front();
				break;
			}
		}
	}
	string answer;
	for (int i = 0; i < Lstack.size(); i++)
		answer.push_back(Lstack[i]);
	for (int i = 0; i < Rstack.size(); i++)
		answer.push_back(Rstack[i]); 
	while (answer.find(A) < 30000) 
		answer.erase(answer.find(A), A.size());
	if (!answer.empty()) cout << answer << '\n';

}