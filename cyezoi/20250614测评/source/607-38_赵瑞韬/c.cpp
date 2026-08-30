#include<bits/stdc++.h>
int n,a[5002];
long long f[5001][5001],ans=1e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	printf("0");
	if(n==1)return 0;
	for(int i=1;i<n;i++){
		f[2][i]=abs(a[i]-a[i+1]);
		ans=std::min(ans,f[2][i]);
	}
	printf(" %lld",ans);
	if(n==2)return 0;
	for(int k=3;k<=n;k++){
		ans=1e9;
		for(int i=n-k+1;i>=1;i--){
			f[k][i]=f[k-2][i+1]+abs(a[i]-a[i+k-1]);
			ans=std::min(ans,f[k][i]);
		}
		printf(" %lld",ans);
	}
	return 0;
}

