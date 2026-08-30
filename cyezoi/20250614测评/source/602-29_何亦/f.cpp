#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+3;
int nums[maxn],dp[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>nums[i];
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
	}
	cout<<dp[n];
	return 0;
}
