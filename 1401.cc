#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int search(int n) {
	int ret = 0;
	for (int i = 5; n/i>=1; i *= 5)
		ret += n/i;
	return ret;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", search(n));
	}
	return 0;
}
