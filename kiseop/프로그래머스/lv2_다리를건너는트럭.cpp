#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int sum = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		int now = truck_weights[i];
		while (true)
		{
			if (q.empty()) {
				q.push(now);
				answer++;
				sum += now;
				break;
			}
			else if (q.size() == bridge_length) {
				sum -= q.front(); 
				q.pop();
			}
			else{
				if (sum + now > weight) {
					q.push(0);
					answer++;
				}
				else {
					q.push(now);
					answer++;
					sum += now;
					break;
				}
			}
		}
	}
	answer += bridge_length;
	return answer;
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 });

}