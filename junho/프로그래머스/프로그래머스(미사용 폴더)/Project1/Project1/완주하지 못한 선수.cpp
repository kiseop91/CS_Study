#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size(); i++) {
		if (i == participant.size() - 1) {
			answer = participant[i];
			return answer;

		}
		if (participant[i] != completion[i]) { 
			
			answer= participant[i];
		return answer;
		}
	}
	
}
int main() {
	vector<string>participant;
	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");

	vector<string> completion;
	completion.push_back("eden");
	completion.push_back("kiki");
solution(participant, completion);

}