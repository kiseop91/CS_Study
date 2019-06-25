#include <iostream>
#include <string>
#include <cstring>//memset을 쓰려면 cstring
 
using namespace std;

bool arr[21];
int N;

void add(int a) {
	if (arr[a] == false) { arr[a] = true; return; }
	return;
}
void remove(int a){
	if (arr[a] == true) { arr[a] = false; return; }
	return;
}
void check(int a) {
	if (arr[a] == true) { cout << "1" << "\n"; }
	else { cout << "0" << "\n"; }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	string str;
	int temp;
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "add") {
			cin >> temp;
			add(temp);
		}
		else if(str == "remove"){
			cin >> temp;
			remove(temp);
		}
		else if (str == "check") {
			cin >> temp;
			check(temp);
		}
		else if (str == "toggle") {
			cin >> temp;
			if (arr[temp] == true) { arr[temp] = false; }
			else
			{
				arr[temp] = true;
			}
		}
		else if (str == "all") {
			memset(arr, true, sizeof(arr));
		}
		else if (str == "empty") {
			memset(arr, false, sizeof(arr));

		}

	}

}

