#include <cstdio>
#include <cstring>
using namespace std;
int cnt[26];

int main() {
//	freopen("in.txt", "r", stdin);	
	memset(cnt, 0, sizeof cnt);
	int mx = -1;
	char c; while (scanf("%c", &c) != EOF) {
		if (c>='A' && c<='Z') {
			mx = (++cnt[c-'A'])>mx?cnt[c-'A']:mx;
		}
	}
	for (int i = mx; i > 0; i--) {
		for (int j = 0; j < 25; j++)
			printf("%c ", cnt[j]>=i?'*':' ');
		printf("%c", cnt[25]>=i?'*':' ');
		printf("\n");
	}
	for (int i = 0; i < 25; i++)
		printf("%c ", i+'A');
	printf("Z");
	return 0;
}
