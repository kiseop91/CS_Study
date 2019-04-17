#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int div(int n)
{
	int ret = n;
	while (n > 0)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}
int main()
{
	int n;
	cin >> n;
	int res = INT32_MAX;

	for (int i = 1; i < n; i++)
	{
		if (n == div(i))
			res = min(i, res);
	}

	if (res == INT32_MAX)
		cout << 0;
	else
		cout << res;

	return 0;
}
