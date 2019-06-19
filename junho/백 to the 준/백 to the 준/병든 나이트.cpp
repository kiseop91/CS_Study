#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int H = 0;
	int W = 0;
	cin >> H >> W;
	
	if (H == 1) {
		cout << 1 << endl;
	}
	else if (H == 2) {
		cout << min(4, (W + 1) / 2);
	}
	else {
		if (W >=7 ) {
			cout << W - 2<<endl;
		}
		else {
			cout << min(4, W);
		}
	}


}