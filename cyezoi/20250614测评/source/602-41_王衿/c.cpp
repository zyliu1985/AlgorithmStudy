#include <bits/stdc++.h>

using namespace std;

int n, h[5005];
long long tmp, ans[5005];
int main() {
	memset(ans, 127, sizeof ans);
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &h[i]);
	}
	ans[1] = 0;
	for (int i=2; i<=n; ++i) {
		tmp = 0;
		for (int k=1;; ++k) {
			if (i - k < 1 || i + k > n) break;
			tmp += abs(h[i - k] - h[i + k]);
			ans[1 + 2 * k] = min(ans[1 + 2 * k], tmp);
		}
	}
	for (int i=1; i<=n; ++i) {
		tmp = 0;
		for (int k=1;; ++k) {
			if (i - k + 1 < 1 || i + k > n) break;
			tmp += abs(h[i - k + 1] - h[i + k]);
			ans[2 * k] = min(ans[2 * k], tmp);
		}
	}
	printf("0");
	for (int i=2; i<=n; ++i) {
		printf(" %lld", ans[i]);
	}
	printf("\n");
	return 0;
}
