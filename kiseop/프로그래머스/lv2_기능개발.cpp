#include <string>
#include <vector>
#include <queue>
using namespace std;

struct item {
	int idx, remain;
};
int reamin_val(double n)
{
	if (n > (int)n)
		return (int)n + 1;
	else
		return (int)n;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<item> v;
	int idx = 0;
	for (int i = 0; i < progresses.size(); i++)
	{
		int rm = reamin_val((100 - progresses[i]) / (double)speeds[i]);
		v.push_back({ i,rm });
	}

	int max = v[0].remain;
	int cnt = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (max < v[i].remain)
		{
			max = v[i].remain;
			answer.push_back(cnt);
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	answer.push_back(cnt);
	return answer;
}