#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
	bool answer = true;
	int size = s.size();
	if (size == 4 or size == 6)
	{

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' and s[i] <= '9')
				continue;
			else
				return false;
		}
	}
	else{
		return false;
    }
    return answer;
}

int main()
{
	cout << solution("1234567a") << endl;
}