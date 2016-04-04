#include <cstdio>
#include <cstdlib>
#include <cmath>
#define N 10010
using namespace std;

//recursive version
//finds a^n in O(log(n)) time
double pow_rec(double a, int n) {
	if (!n) return 1;
	if (n == 1) return a;
	double ret = pow_rec(a, n/2);
	return ret*ret*pow_rec(a, n%2);
}

//non-recursive version
//finds a^n in O(log(n)) time
double pow_it(double a, int n) {
	double ret = 1.0;
	while (n) {
		if (n%2) ret *= a;
		a *= a; n /= 2;
	}
	return ret;
}

//finds if given n is prime
//O(sqrt(n))
bool is_prime(int n) {
	if (n == 2) return 1;
	if (n<=1 || !(n%2)) return 0;
	int m = (int)sqrt(n);

	for (int i = 3; i <= m; i += 2)
		if (!(n%i)) return 0;
	return 1;
}

bool primes[N];
void find_primes(int n) {
	primes[0] = primes[1] = 1;
	int m = (int)sqrt(n);
	for (int i = 2; i <= m; i++)
		if (!primes[i])
			for (int k = i*i; k <= n; k += i)
				primes[k] = 1;
	for (int i = 1; i <= n; i++)
		if (!primes[i])
			printf("%d ", i);
}

int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}

int gcd_brute(int a, int b) {
	for (int i = min(a, b); i >= 1; i--)
		if (a%i==0 && b%i==0) 
			return i;
}

//finds (gcd(u, v), (x, y)) such that
//gcd(u, v) = x*u+y*v
pair <int, pair<int, int> > egcd(int u, int v) {
	if (v == 0) return make_pair(u, make_pair(1, 0));
	pair <int, pair <int, int> > ret = egcd(v, u%v);
	int xx = ret.second.first, yy = ret.second.second;
	int q = u/v;
	ret.second.first = yy;
	ret.second.second = xx-q*yy;
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	find_primes(n);
	return 0;
}
