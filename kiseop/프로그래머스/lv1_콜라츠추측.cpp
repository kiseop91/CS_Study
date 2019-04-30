#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int answer = 0;

	long long num2 = num;
	while (num2 != 1)
	{
		if (num2 % 2 == 0) {
			num2 = num2 / 2;
			answer++;
			if (num2 == 1)
				return answer;
		}
		if (answer >= 500)
			return -1;
		if (num2 % 2 == 1)
		{
			num2 = num2 * 3;
			num2++;
			answer++;
		}

		if (answer >= 500)
			return -1;
	}
	return answer;
}