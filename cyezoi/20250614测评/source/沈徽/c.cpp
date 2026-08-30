#include <bits/stdc++.h>
using namespace std;
int n,a[100010],f[5010][5010];
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 0;i < n;i++){
		for (int l = 1;l + i <= n;l++){
			for (int j = 0;j <= i / 2;j++) f[l][l+i] += abs(a[l+j] - a[l+i-j]);
		} 
	}
	for (int i = 0;i < n;i++){
		int ans = 0x3f3f3f3f;
		for (int l = 1;l + i <= n;l++) ans = min(ans,f[l][l+i]);
		cout << ans << ' ';
	}
}
