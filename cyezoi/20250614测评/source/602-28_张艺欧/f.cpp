#include<bits/stdc++.h>
using namespace std;
int n, m, step, a[3010], b[110], f[4010][3];
bool vis[3010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cin >> m;
	for(int i=1; i<=m; ++i){
		cin >> b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			f[step][0] = max(f[step-1][0], max(f[step-1][2], f[step-1][1]));
			f[step][1] = f[step-1][0]+a[i];
			f[step][2] = f[step-1][0]+b[j];
			if(f[step][1]>f[step][0] || f[step][2]>f[step][0]) step++;
		}
	}
	cout << max(f[n+m][2], max(f[n+m][0], f[n+m][1])) << endl;
	return 0;
}
