#include <cstdio>
#include <cstdio>
using namespace std;

int main() {
	double ret = 0.0;
	for (size_t i=0; i<12; i++) {
		double money; scanf("%lf", &money);
		ret += money;
	}
	printf("$%.2lf\n", ret/12.0);
	return 0;
}
