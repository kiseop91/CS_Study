#include <iostream>
#include <cstring>
using namespace std;

int arr[550000];
bool channel[12];
int target;

int main() {
	int a;
	cin >> a;
	int temp;
	
	memset(channel, true, sizeof(channel));

	for (int i = 0; i < a; i++) {
		cin >> temp;
		channel[temp] = false;
	}

	







}


