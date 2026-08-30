#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[3005],m,b[105];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}if(m==0){
		int dp[3005];
		dp[1]=a[1];
		for(int i=1;i<=n;i++){
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		}
		cout<<dp[n];
	}
	if(m==1){
		int cnt1=0,cnt2=0;
		
		for(int i=1;i<=n;i+=2){
			cnt1+=a[i];
		}
		for(int i=2;i<=n;i+=2){
			cnt2+=a[i];
		}
		cout<<max(cnt1,cnt2);
	}
}
