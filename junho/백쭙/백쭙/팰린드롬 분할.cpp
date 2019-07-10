#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int Dp[2501][2501];
int result[2501];
int main(void) {

	char room[2501];
	string size;
	int roomSize;
	cin >> room;
	size = room;
	roomSize = size.size();

	for (int i = 1; i <= roomSize; i++)
		Dp[i][i] = 1;
	for (int i = 1; i <= roomSize - 1; i++)
		if (room[i - 1] == room[i])
			Dp[i][i + 1] = 1;

	for (int i = 2; i <= roomSize - 1; i++)
		for (int j = 1; i + j <= roomSize; j++)
			if (room[j - 1] == room[j + i - 1] && Dp[j + 1][i + j - 1] == 1)
				Dp[j][i + j] = 1;

	for (int i = 1; i <= roomSize; i++) {
		if ((result[i] != 0 && result[i] > result[i - 1] + 1) || result[i] == 0)
			result[i] = result[i - 1] + 1;

		for (int j = i + 1; j <= roomSize; j++) {
			if (Dp[i][j] != 0)
			{
				if ((result[j] != 0 && result[j] > result[i - 1] + 1) || result[j] == 0)
					result[j] = result[i - 1] + 1;
			}
		}

	}
	printf("%d\n", result[roomSize]);
	return 0;
}