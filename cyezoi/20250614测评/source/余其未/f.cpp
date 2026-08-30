#include<bits/stdc++.h>
#define N 3005
#define M 105
typedef long long ll;
using namespace std;
ll n,m,ans,a[N],b[M],c[N+M],dp[2][N];
void pts_20(){
	dp[1][1]=a[1];
	for(ll i=2;i<=n;i++){
		dp[0][i]=dp[1][i-1];
		dp[1][i]=max(dp[1][i-2],dp[0][i-1])+a[i];
	}
	cout<<max(dp[0][n],dp[1][n]);
}
void pts_40(){
	for(ll k=1;k<=n+1;k++){
		for(ll i=1;i<=n+1;i++)
			if(i==k) c[i]=b[1];
			else if(i<k) c[i]=a[i];
			else if(i>k) c[i]=a[i-1];
		dp[1][1]=c[1];
		for(ll i=2;i<=n+1;i++){
			dp[0][i]=dp[1][i-1];
			dp[1][i]=max(dp[1][i-2],dp[0][i-1])+c[i];
		}
		ans=max(ans,max(dp[0][n+1],dp[1][n+1]));
	}
	cout<<ans;
}
void hack(){
	for(ll i=1;i<=n;i++) c[i]=a[i];
	for(ll i=1;i<=m;i++) c[n+i]=b[i];
	sort(c+1,c+1+n+m,greater<ll>() );
	for(ll i=1;i<=(n+m+1)/2;i++) ans+=c[i];
	cout<<ans;
}
void pts_60(){
	hack();
}
void pts_100(){
	hack();
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(ll i=1;i<=m;i++) cin>>b[i];
	if(m==0) pts_20();
	else if(m==1) pts_40();
	else if(m<=10) pts_60();
	else pts_100();
	return 0;
}
