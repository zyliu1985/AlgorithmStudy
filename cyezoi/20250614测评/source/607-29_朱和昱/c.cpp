#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int dp[5005][5005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=2;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			dp[k][i]=dp[k-2][i+1]+abs(a[i]-a[i+k-1]);
		}
	}
	for(int k=1;k<=n;k++){
		int minx=10000000000000;
		for(int i=1;i<=n-k+1;i++){
			minx=min(minx,dp[k][i]);
		}
		cout<<minx<<" ";
	}
	return 0;
}
