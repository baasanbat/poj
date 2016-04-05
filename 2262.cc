#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int n) {
	if (n == 2) return 1;
	if (n<=1 || n%2==0) return 0;
	int m = sqrt(n);
	for (int i = 3; i <= m; i += 2)
		if (n%i == 0) return 0;
	return 1;
}

int main() {
	int n; while (scanf("%d", &n) && n) {
		bool found = 0;
		int i;
		for (i = 3; i <= n/2; i += 2)
			if (is_prime(i) && is_prime(n-i)) {
				found = 1;
				break;
			}
		if (found)
			printf("%d = %d + %d\n", n, i, n-i);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
