#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,d,ans;
int a[200005],b[200005];

signed main() {
//	freopen("b.in","r",stdin);
//	freopen("b.ans","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1 && a[i] == 1 && b[i] == 1) {
			d++;
		} 
		if(a[i] == 1 && a[i-1] == 1) d++;
		if(b[i] == 1 && b[i-1] == 1) d++;
		if(a[i] == 1) ans++;
		if(b[i] == 1) ans++;
	}
	cout << ans * 3 - d * 2;
	return 0;
}



