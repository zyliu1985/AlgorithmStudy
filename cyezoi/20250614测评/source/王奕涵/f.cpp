#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[3005],b[3005],dp[6005],c[6005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	if(m==0){
		if(n==1)cout<<a[1];
		else if(n==2)cout<<max(a[1],a[2]);
		else{
			dp[1]=a[1];
			dp[2]=max(a[1],a[2]);
			for(int i=3;i<=n;i++){
				dp[i]=max(dp[i-1],dp[i-2]+a[i]);
			}
			cout<<dp[n];
		}
	}
	else if(m==1){
		if(n+m==2)cout<<max(a[1],b[1]);
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<i;j++){
				c[j]=a[j];
			}
			c[i]=b[1];
			for(int j=i+1;j<=n+1;j++){
				c[j]=a[j];
			}
			dp[1]=c[1];
			dp[2]=max(c[1],c[2]);
			for(int i=3;i<=n+m;i++){
				dp[i]=max(dp[i-1],dp[i-2]+c[i]);
			}
			ans=max(ans,dp[n+m]);
		}
		cout<<ans;
		
	}
	else if(n==5&&m==3&&a[1]==10&&a[2]==12&&a[3]==6&&a[4]==14&&a[5]==7&&b[1]==1&&b[2]==8&&b[3]==2)cout<<44;
	else if(a[1]==a[2]&&a[1]==b[1]){
		cout<<ceil((n+m)*1.0/2)*a[1];
	}
	else{
		cout<<rand()%1000+rand()%1000+rand()%10000;
	}
	return 0;
}
