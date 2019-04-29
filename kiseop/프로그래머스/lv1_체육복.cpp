#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool chk[30];
bool lchk[30];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i = 0; i < reserve.size(); i++)
	{
		int idx = reserve[i];
		chk[idx] = true;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		int idx = lost[i];
		lchk[idx] = true;
		if (chk[idx]) {
			lchk[idx] = false;
			chk[idx] = false;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!lchk[i]) {
			answer++;
		}
		else {
			if (chk[i - 1]) {
				answer++;
				chk[i - 1] = false;
			}
			else if (chk[i + 1]) {
				answer++;
				chk[i + 1] = false;
			}
		}
	}
	return answer;
}
