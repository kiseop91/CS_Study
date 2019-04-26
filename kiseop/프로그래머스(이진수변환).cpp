#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int onenum = 0;

string make_binary_number(int n)
{
	string s = "";
	while (n >= 3)
	{
		if (n == 2)
		{
			onenum++;
			s.push_back('0');
			s.push_back('1');
		}
		else if (n == 3)
		{
			onenum++;
			s.push_back('1');
			s.push_back('1');
		}
		else {
			int t = n % 2;
			if (t == 1) {
				onenum++;
				s.push_back('1');
			}
			else
				s.push_back('0');
		}
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int bton(string s)
{
	int val = s[s.length()-1] -'0';
	int m = 2;
	for (int i = s.length() - 2; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			val += m;
		}
		m *= 2;
	}
	return val;
}
int main()
{
	int n;
	cin >> n;
	string number = make_binary_number(n);
	cout << onenum<<"  " << number << " " << bton(number) << endl;
	bool chk = true;
	int onenumber = onenum;
	while (chk)
	{
		n++;
		onenum = 0;
		string thisnum = make_binary_number(n);
		if (onenum == onenumber)
		{
			chk = false;
			cout <<n<<" : ";
			cout << onenum << "  " << number << " " << bton(number) << endl;
		}
	}
	return 0;
}