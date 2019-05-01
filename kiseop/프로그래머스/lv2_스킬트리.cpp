#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>	
#include <math.h>
#include <queue>
#include <string>

using namespace std;

int solution(string skill, vector <string> skill_trees) {

	string init = "";
	//string chk = "";
	int answer = 0;

	for (auto x : skill_trees)
	{
		string chk;
		for (int i = 0; i < x.length(); i++) {
			if (skill.find(x[i]) != string::npos)
			{
				chk.push_back(x[i]);
			}
		}
		for (int i = 0; i < chk.size(); i++)
		{
			if (skill[i] != chk[i])
			{
				answer++;
				break;
			}
		}
	}
	answer = skill_trees.size() - answer;
	return answer;
}

int main()
{
	cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
}