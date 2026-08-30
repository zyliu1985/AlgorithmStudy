#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[3004];
int b[103];
int dp[3005][2];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		cin>>b[i];
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=dp[i-1][0]+a[i];
		}
		cout<<max(dp[n][0],dp[n][1]);
		return 0;
	}
	cout<<0;
	return 0;
}
