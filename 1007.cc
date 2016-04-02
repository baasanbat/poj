#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> strings;
/*
 * costumized comparing function
 * answering if a is less than b in output
 * works in quadratic time
 */
bool cmp(string a, string b) {
	int aa = 0, bb = 0;
	//counting inverse on a
	for (size_t i = 0; i < a.size(); i++) {
		int ta = 0;
		for (size_t j = i+1; j < a.size(); j++)
			ta += a[i]>a[j];
		aa += ta;
	}
	//counting inverse on b
	for (size_t i = 0; i < b.size(); i++) {
		int tb = 0;
		for (size_t j = i+1; j < b.size(); j++)
			tb += b[i]>b[j];
		bb += tb;
	}
	return aa<bb;
}

int main() {
	int n, m; cin >> n >> m; 
	while (m--) {
		string s; cin >> s;
		strings.push_back(s);
	}
	sort(strings.begin(), strings.end(), cmp);
	for (size_t i = 0; i < strings.size(); i++)
		cout << strings[i] << endl;
	return 0;
}
