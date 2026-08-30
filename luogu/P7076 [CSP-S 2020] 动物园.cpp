#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool flag[100000005], vis[70];
unsigned long long ans = 1;
unsigned long long a[1000005];
vector<int> v[70];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, c, k;
	cin >> n >> m >> c >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		int p, q;
		cin >> p >> q;
		v[p].push_back(q);
	}
	for (int i = 1; i <= n; i++){
		int now = 0;
		while (a[i] > 0){
			if (a[i] & 1 && !vis[now]){
				ans <<= 1;
				vis[now] = 1;
				for (int j = 0; j < v[now].size(); j++)
					flag[v[now][j]] = 1;
			}
			now++;
			a[i] >>= 1;
		}
	}
	for (int i = 0; i < k; i++)
		if (!vis[i]){
			bool ok = 1;
			for (int j = 0; j < v[i].size(); j++)
				if (!flag[v[i][j]]) ok = 0;
			ans <<= ok;
		}
	if (n > 0 || ans != n) cout << ans - n << '\n';
	else cout << "18446744073709551616\n";
	return 0;
}

