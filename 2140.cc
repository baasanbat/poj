#include <cstdio>
using namespace std;

int main() {
	int ret = 1;
	int n; scanf("%d", &n);
	for (int i = (n+1)/2; i >= 1; i--) {
		int current = 0, idx = i;
		while (current<n && idx>0) {
			current += idx--;
		}
		if (current == n) ret++;
	}
	printf("%d\n", ret);
	return 0;
}
