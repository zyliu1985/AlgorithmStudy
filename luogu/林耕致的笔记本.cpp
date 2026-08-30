#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double p[1000005];
int vis[1000005];
int main(){
//	freopen("17.in", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		p[i] /= 2;
	}
	for (int i = 1; i <= m; i++){
		int op;
		cin >> op;
		if (op == 1){
			double ans = 1;
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++){
				int a;
				cin >> a;
				if (vis[a] != i) ans *= p[a], vis[a] = i;
			}
			printf("%f\n", ans);
		} else {
			int x;
			cin >> x;
			p[x] = 1;
		}
	}
	return 0;
}



