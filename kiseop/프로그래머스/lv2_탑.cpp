#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>	
#include <math.h>
#include <queue>
#include <string>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	for (int i = heights.size() - 1; i >= 1; i--)
	{
		bool chk = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (heights[i] < heights[j]) {
				answer.push_back(j + 1);
				chk = false;
				break;
			}
		}
		if (chk)
			answer.push_back(0);
	}
	answer.push_back(0);
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	vector<int> v = solution({ 1,5,3,6,7,6,5 });

	for (auto x : v)
		cout << x << " ";
}