#include <bits/stdc++.h>
using namespace std;
//#define int ll
#define ll long long

int n,m,a[3205],b[3205],f[3205][2];

int dp(int n){
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=f[i-1][0]+a[i];
	}
	return max(f[n][0],f[n][1]);
}

bool check(int x){
	return 1;
}

signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(b+1,b+1+m);
	if(m==0){
		cout<<dp(n);
		return 0;
	}
	if(m==1){
		a[++n]=b[1];
		int ans=0;
		for(int i=n;i>1;i--){
			ans=max(ans,dp(n));
			swap(a[i],a[i-1]);
		}
		cout<<ans<<endl;
		return 0;
	}
	int l=1,r=10e9,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	
	return 0;
}
