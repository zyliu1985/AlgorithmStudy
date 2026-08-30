#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[5005];
int f[5005][5005], ans[5005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(ans, 0x3f, sizeof(ans));
	ans[1] = 0;
	for (int i = 1; i < n; i++)
		f[i][i+1] = abs(a[i] - a[i+1]), ans[2] = min(ans[2], f[i][i+1]);
	for (int len = 3; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			f[i][j] = f[i+1][j-1] + abs(a[i] - a[j]);
			ans[len] = min(ans[len], f[i][j]);
		}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}
