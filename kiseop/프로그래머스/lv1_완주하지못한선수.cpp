#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> count;
	for (auto x : participant)
		count[x]++;
	for (auto x : completion)
		count[x]--;
	for (auto x : participant)
		if (count[x]==1)
			return x;
}