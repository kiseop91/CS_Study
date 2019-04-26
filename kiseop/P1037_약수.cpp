#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
    sort(arr.begin(), arr.end());
	if (n % 2 == 1)
	{
		int mid = arr.size() / 2;
		cout << arr[mid] * arr[mid];
	}
	else
	{
		int min = *arr.begin();
		int max = *(arr.end() - 1);
		cout << min * max;
	}
}