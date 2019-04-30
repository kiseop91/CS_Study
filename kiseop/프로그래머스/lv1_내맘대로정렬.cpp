#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
struct cmp {
	bool operator()(const string& lhs, const string& rhs)
	{
		if (lhs[N] == rhs[N])
		{
			return lhs > rhs;
		}
		return lhs[N] > rhs[N];
	}
};
vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	N = n;
	priority_queue <string, vector<string>, cmp> pq;
	for (int i = 0; i < strings.size(); i++)
		pq.push(strings[i]);

	while (!pq.empty()) {
		answer.push_back(pq.top());
		pq.pop();
	}

	return answer;
}


int main()
{
	vector<string> ans = solution({ "abce", "abcd", "cdx" }, 2);

	for (const auto x : ans)
		cout << x << endl;
}