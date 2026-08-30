# include <bits/stdc++.h>
using namespace std;
int n,h[5010],a[5010][5010];
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> h[i];
	}
	cout << 0;
	for (int i=2;i<=n;i++){
		int ans=500000010;
		for (int l=1;l<=n-i+1;l++){
			int r=l+i-1;
			if (l+1<=r-1){a[l][r]+=a[l+1][r-1];}
			a[l][r]+=abs(h[l]-h[r]);
			ans=min(ans,a[l][r]);
		}
		cout << ' ' << ans;
	}
	return 0;
}
