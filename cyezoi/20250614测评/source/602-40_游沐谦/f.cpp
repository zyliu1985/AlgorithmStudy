#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[3005],b[105];
int f[3005];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	if(m == 0) {
		f[1] = a[1];
		f[2] = max(a[1],a[2]);
		for(int i = 3; i <= n; i++) {
			f[i] = max(f[i-2] + a[i],f[i-1]);
		}
		cout << f[n];
	}
	if(m == 1) {
		int c[3005];
		for(int i = 0; i <= n; i++) {
			memset(c,0,sizeof(c));
			memset(f,0,sizeof(f));
			int j;
			for(j = 1; j <= i; j++) {
				c[j] = a[j];
			}
			c[j] = b[1];
			j++;
			for(; j <= n+1; j++) {
				c[j] = a[j-1];
			}
			//for(int k = 1; k <= n+1; k++) cout << c[k] << ' ';
//			cout << endl;
			f[1] = c[1];
			f[2] = max(c[1],c[2]);
			for(int t = 3; t <= n+1; t++) {
				f[t] = max(f[t-2] + c[t],f[t-1]);
			}
			ans = max(ans,f[n+1]);
			//cout << f[n+1] << endl;
		}
		cout << ans;
	}
}
