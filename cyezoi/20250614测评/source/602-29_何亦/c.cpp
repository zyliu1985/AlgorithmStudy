#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+3;
int nums[maxn],ans[maxn],sum1[maxn][maxn],sum2[maxn],dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	memset(ans,0x3f,sizeof(ans));
	for(int len=1;len<=2;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r]=abs(nums[l]-nums[r]);
			ans[len]=min(ans[len],dp[l][r]);
		}
	}
	for(int len=3;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r]=dp[l+1][r-1]+abs(nums[l]-nums[r]);
			ans[len]=min(ans[len],dp[l][r]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
7
3 1 4 1 5 9 2
*/
