#include <iostream>

using namespace std;

int main() {
	int girl = 0;
	int boy = 0;
	int intern = 0;

	cin >> girl >> boy >> intern;
	int result=0;
	while (1) {
		if (girl >= 2 && boy >= 1 && girl + boy >= intern + 3) {
			result += 1;
			girl -= 2;
			boy -= 1;
		}
		else {
			break;
		}
	}
	
	cout << result;

}