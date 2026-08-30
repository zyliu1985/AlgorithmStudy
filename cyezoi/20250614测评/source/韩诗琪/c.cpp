#include<bits/stdc++.h>
using namespace std;

const int N=5005;
const int inf=1e4;

int n,h[N],dp[N][N],ans[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	memset(ans,inf,sizeof(ans));
	ans[1]=0;
	for(int i=2;i<=n;i++){
		for(int l=1,r=l+i-1;l<=n-i+1;l++,r++){
			dp[l][r]=abs(h[l]-h[r])+dp[l+1][r-1];
			ans[i]=min(ans[i],dp[l][r]);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
