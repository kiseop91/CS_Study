#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000 + 1;
int N, M;
int arr[MAX];

void merge(int aParent, int bParent)
{
	if (abs(aParent) >= abs(bParent))
	{
		arr[aParent] += arr[bParent];
		arr[bParent] = aParent;
	}
	else
	{
		arr[bParent] += arr[aParent];
		arr[aParent] = bParent;
	}
}

int findParent(int num)
{
	if (arr[num] < 0)
		return num;
	int parent = findParent(arr[num]);
	arr[num] = parent;
	return parent;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		arr[i] = -1;

	for (int i = 0; i < M; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
		{
			if (a == b) {
				continue;
			}
			int aParent = findParent(a);
			int bParent = findParent(b);
			if (aParent == bParent)
			continue;
			merge(aParent, bParent);
		}
		else
		{
			if (a == b)
			{
				cout << "YES\n";
				continue;
			}
			int aParent = findParent(a);
			int bParent = findParent(b);
			if (aParent == bParent) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;

}