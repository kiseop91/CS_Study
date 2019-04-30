#include <string>
#include <vector>

using namespace std;
int solution(int n) {
    vector<long long> divisors;
    int answer = 0;
    for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) divisors.push_back(n / i);
		}
	}
    for(const auto x : divisors)
        answer+=x;
    return answer;
}