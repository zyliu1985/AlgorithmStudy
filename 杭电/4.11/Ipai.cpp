#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long pw[1000011],dp[1000011];
int main(){
	freopen("in.in", "r", stdin);
	freopen("force.out", "w", stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,k,i;
	long long ans;
	pw[0]=1;
	for(i=1;i<=1000010;i++)pw[i]=pw[i-1]*5%mod;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>k;
		for(i=0;i<=n;i++)dp[i]=0;
		dp[0]=1;
		dp[1]=mod-5;
		for(i=0;i<=n;i++)
		{
			if(i>0)dp[i]=(dp[i]+dp[i-1]*5)%mod;
			if(i+1<=n)dp[i+1]=(dp[i+1]+dp[i]*21)%mod;
			if(i+k+2<=n)dp[i+k+2]=(dp[i+k+2]+mod-dp[i]*21%mod*pw[k+1]%mod)%mod;
		}
		ans=0;
		for(i=n;i>=0&&i>=n-k;i--)ans=(ans+dp[i]*pw[n-i])%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
