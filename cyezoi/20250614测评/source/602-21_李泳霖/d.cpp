#include<bits/stdc++.h>

using namespace std;

#define int long long
int g, p, G[100005], vis[100005];

signed main() {
	scanf("%d%d", &g, &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d", &G[i]);
		if (!vis[G[i]]) vis[G[i]] = 1;
		else {
			bool flag = 0;
			for (int j = G[i] - 1; j >= 1; j--) {
				if (!vis[j]) {
					vis[j] = 1;
					flag = 1;
					break;
				}
			}
			if (!flag) break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= g; i++) {
		if (vis[i]) cnt++;
	}
	printf("%lld", cnt);
	return 0;
}
