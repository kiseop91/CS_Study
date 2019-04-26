#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int target[100001];
int n;
int m;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> target[i];
	}
}

int solve(int tg)
{
	int s = 0;
	int e = n - 1;
	while (s <= e)
	{
		int m = (s + e) / 2;

		if (arr[m] == tg)
		{
			return 1;
		}
		else if (arr[m] > tg)
		{
			e = m - 1;
		}
		else if (arr[m] < tg)
		{
			s = m + 1;
		}

	}
	return 0;
}
int main()

{
	input();
	sort(arr, arr + n);

	for (int i = 0; i < m; i++)
	{
		cout << solve(target[i]) << '\n';
	}

	return 0;
}