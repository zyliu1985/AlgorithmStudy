#include <cstdio>
#include <algorithm>
using namespace std;

int G, n;
struct Node {
	int g, id;
} a[100005];
bool cmp(Node x, Node y) {
	return x.g > y.g;
}

bool check(int mid) {
	int mn = G;
	for (int i = 1; i <= n; i++) {
		if (a[i].id > mid) continue;
		mn = min(mn - 1, a[i].g - 1);
		if (mn < 0) return false;
	}
	return mn >= 0;
}

int main() {
	scanf("%d%d", &G, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].g), a[i].id = i;
	sort(a + 1, a + n + 1, cmp); 
	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
