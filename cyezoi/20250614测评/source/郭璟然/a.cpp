#include <cstdio>
#include <algorithm>
using namespace std;

int n, cnt[10];
char c[10];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		for (int j = 1; j <= 5; j++)
			cnt[j] += (c[j] == 'Y');
	}
	int mx = 0;
	for (int i = 1; i <= 5; i++)
		mx = max(mx, cnt[i]);
	bool flag = false; 
	for (int i = 1; i <= 5; i++)
		if (cnt[i] == mx) {
			if (flag)
				printf(",");
			flag = true;
			printf("%d", i);
		}
	return 0;
}

