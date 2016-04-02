#include <cstdio>
using namespace std;

double compute_length(int n) {
	int bottom = 2;
	double ret = 0.0;
	for (int i=1; i<=n; i++) ret += (1.0/(bottom++));
	return ret;
}

/*
 * O(LogN)
 */
int search_binary(double c) {
	int lo = 0, hi = 276;
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (compute_length(mid) >= c) 
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

/*
 * O(N)
 */
int search_linear(double c) {
	int ret = 1;
	double current = 0.5;
	while (c > current) {
		current = compute_length(++ret);
	}
	return ret;
}

int main() {
	double c;
	while (1) {
		scanf("%lf", &c); if (c == 0.0) break;
		printf("%d card(s)\n", search_binary(c));
	}
	return 0;
}
