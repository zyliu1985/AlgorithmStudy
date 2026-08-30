#include<bits/stdc++.h>
using namespace std;
int a[3010],b[110],dp[4010];
int main(){
	srand(time(0));
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	if(m==0){
		for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		cout<<dp[n];
	}
	else if(m==1){
		a[++n]=b[1];
		int mx=0;
		for(int i=1;i<n;i++){
			swap(a[n-i+1],a[n-i]);
			for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],dp[i-2]+a[i]);
			mx=max(dp[n],mx);
		}
		cout<<mx;
	}
	else cout<<"IAKIOI";
	return 0;
}
