#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],dp[300005],c[300005],ddp[300005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	if(m==1){
		for(int k=1;k<=n+1;k++){
			for(int j=1;j<=n+1;j++){
				if(j==k) c[j]=b[1];
				if(j<k) c[j]=a[j];
				if(j>k) c[j]=a[j-1];
			}
			for(int i=3;i<=n+1;i++){
				dp[i]=max(dp[i-3]+c[i],dp[i-2]+c[i]);
			}
			ddp[k]=max(dp[n+1],dp[n]);
		}
		int maxx=-1;
		for(int i=1;i<=n;i++) {
			if(ddp[i]>maxx) maxx=ddp[i];
		}
		cout<<maxx;
	}else{
		for(int i=3;i<=n;i++){
			dp[i]=max(dp[i-3]+dp[i],dp[i-2]+dp[i]);
		}
		cout<<max(dp[n],dp[n-1]);
	}
	return 0;
}
