#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
	string answer = "";
	//1월 1일은 금요일, 2월은 29일까지있음.
	int day = 0;
	for (int i = 1; i < a; i++)
	{
		if (i <= 7)
		{
			if (i % 2 == 1)
			{
				day += 31;
			}
			else if (i % 2 == 0)
			{
				if (i == 2)
					day += 29;
				else
					day += 30;
			}
		}
		else
		{
			if (i % 2 == 1)
			{
				day += 30;
			}
			else if (i % 2 == 0)
			{
				day += 31;
			}
		}
	}

	day += b-1;
	int today = day % 7;

	if (today == 0)
		return "FRI";
	if (today == 1)
		return "SAT";
	if (today == 2)
		return "SUN";
	if (today == 3)
		return "MON";
	if (today == 4)
		return "TUE";;
	if (today == 5)
		return "WED";
	if (today == 6)
		return "THU";
}

int main()
{

	std::cout << solution(5, 24);
}