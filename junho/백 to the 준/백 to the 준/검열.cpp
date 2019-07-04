#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	string a;//= "aba";
	string T;//= "ababacccabaababaaa";
	cin >> a >> T;

	deque<char> left;
	deque<char> right;

	int low = 0;
	int high = T.size() - 1;


	while (low <= high) {

		//왼쪽부터 검사
		while (low <= high)
		{
			left.push_back(T[low]);
			low += 1;
		
			bool flag = false;
			if (left.size() >= a.size()) {
				flag = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != left[left.size() - a.size() + i]) {
						 flag = false;
						 break;
					}
				}
				if (flag) {
					for (int i = 0; i < a.size(); i++) {
						left.pop_back();
					}
					break;
				}	
			}
		}

		//오른쪽 부터 검사
		while (low <= high) {
			right.push_front(T[high]);
			high -= 1;
			bool flag = false;
			if (right.size() >= a.size()) {
			 flag = true;
				
				for (int i = 0; i < a.size(); i++) {
					if (right[i] != a[i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int i = 0; i < a.size(); i++) {
						right.pop_front();
					}
					break;
				}	
			}

		}




		}

	string ans="";
	for (int i = 0; i < left.size(); i++) {
		ans += left[i];
	
	}
	for (int i = 0; i < right.size(); i++) {
		ans += right[i];
	}


	for (int i = 0; i < ans.size() - a.size(); i++) {
		bool flag = true;
		int z = i;
		if (ans.size() >= a.size()) {
			for (int j = 0; j < a.size(); j++) {
				if (a[j] != ans[i + j]) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				ans.erase(z,z+a.size());
			}
		}
	}
	cout << ans;

}