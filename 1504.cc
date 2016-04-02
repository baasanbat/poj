#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string solve(string a, string b) {
	string ret = "";
	bool carry = 0;
	bool first_non_zero = 0;
	for (size_t i = 0, j = 0; i<a.size() || j<b.size(); i++, j++) {
		int aa = i<a.size()?a[i]-'0':0;
		int bb = j<b.size()?b[j]-'0':0;
		int sum = aa+bb+carry;
		carry = sum>=10;
		int cc = sum%10;
		if (!cc) {
			if (first_non_zero) ret += '0';
		} else {
			first_non_zero = 1;
			ret += cc+'0';
		}
	}
	if (carry) ret += '1';

	return ret;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
