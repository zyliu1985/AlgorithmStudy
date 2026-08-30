#include<bits/stdc++.h>

using namespace std;

int G, p, g, ans, tmp, tmp2, tmp3, a[100005];

int main() {
	//freopen("data.in", "r", stdin);
	scanf("%d", &G);
	scanf("%d", &p);
	ans = p;
	for (int i=0; i<=G; ++i) {
		a[i] = i;
	}
	for (int i=0; i<p; ++i) {
		scanf("%d", &g);
		tmp = tmp2 = g;
		while (a[tmp] != tmp) {
			tmp = a[tmp];
		}
		while (a[tmp2] != tmp2) {
			tmp3 = a[tmp2];
			a[tmp2] = tmp;
			tmp2 = tmp3;
		}
		if (a[g] == 0) {
			ans = i;
			break;
		}
		a[a[g]] = a[g] - 1;
		a[g] = a[a[g]];
	}
	printf("%d\n", ans);
	return 0;
}
