#include <string>
#include <iostream>
using namespace std;

pair <string, int> count_inverse(string s) {
	size_t sz = s.size();
	int ret = 0;
	if (sz == 1)
		return make_pair(s, ret);
	pair <string, int> left = count_inverse(s.substr(0, sz/2));
	pair <string, int> right = count_inverse(s.substr(sz/2, sz-sz/2));
	ret = left.second+right.second;
	size_t szl = left.first.size(), szr = right.first.size();
	string ss;
	for (size_t i = 0, j = 0;;) {
		if (i == szl) {
			while (j < szr) {
				ss += right.first[j++];
			}
			break;
		} else if (j == szr) {
			while (i < szl) {
				ss += left.first[i++];
			}
			break;
		} else if (left.first[i] > right.first[j]) {
			ss += right.first[j++];
			ret += (szl-i);
		} else if (left.first[i] < right.first[j]) {
			ss += left.first[i++];
		} else {
			ss += left.first[i]+left.first[i];
			i++; j++;
		}
	}
	return make_pair(ss, ret);
}

int main() {
	string s; cin >> s;
	pair <string, int> ret = count_inverse(s);
	cout << ret.second << " " << ret.first << endl;
	return 0;
}
