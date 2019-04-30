#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;

	priority_queue<int,vector<int>,greater<int>> pq;
	for (auto x : d)
		pq.push(x);
	int sum=0;
	while (!pq.empty())
	{
		int now = pq.top();
		if (sum + now <= budget) {
			answer++;
			sum += now;
		}
		else
			break;
		pq.pop();

	}

	return answer;
}

int main()
{
	cout << solution({ 1, 3, 2, 5, 4 }, 9);
}