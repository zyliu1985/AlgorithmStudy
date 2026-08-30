#include<bits/stdc++.h>
int n,m,a[3001],b[101],c[3200],dp[3200];
int cal(){
	dp[0]=0,dp[1]=c[1];
	for(int i=2;i<=n+m;i++)dp[i]=std::max(dp[i-1],dp[i-2]+c[i]);
	return dp[n+m];
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)c[i]=a[i];
	if(m){
		c[n+1]=*std::max_element(b+1,b+m+1);
		m=1;
		int ans=0;
		for(int i=n;i>=1;i--){
			ans=std::max(ans,cal());
			std::swap(c[i],c[i+1]);
		}
		printf("%d",std::max(ans,cal()));
	}else{
		printf("%d",cal());
	}
	return 0;
}

