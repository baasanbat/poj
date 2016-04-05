#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const double pi = 3.1415926535897;
int main() {
	int t, i=0; scanf("%d", &t);
	while (t--) {
		double R; int n; scanf("%lf%d", &R, &n);
		printf("Scenario #%d:\n%.3lf\n\n", ++i, R*(sin(pi/n)/(1+sin(pi/n))));
	}
	return 0;
}
