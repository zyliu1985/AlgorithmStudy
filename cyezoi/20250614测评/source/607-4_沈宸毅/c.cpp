#include<bits/stdc++.h>
using namespace std;
int n;
long long mi=0x3f3f3f3f3f3f3f3fll,a[5010],sum[5010][5010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}for(int i=1;i<=n;i++){
		int l=i,r=i;
		sum[i][i]=0;
		while(l>=2&r<=n-1){
			l--,r++;
			sum[l][r]=sum[l+1][r-1]+abs(a[l]-a[r]);
		}
	}for(int i=1;i<=n-1;i++){
		int l=i,r=i+1;
		sum[i][i+1]=abs(a[i]-a[i+1]);
		while(l>=2&r<=n-1){
			l--,r++;
			sum[l][r]=sum[l+1][r-1]+abs(a[l]-a[r]);
		}
	}for(int i=1;i<=n;i++){
		mi=0x3f3f3f3f3f3f3f3fll;
		for(int j=1;j+i-1<=n;j++){
			mi=min(mi,sum[j][j+i-1]);
		}printf("%lld ",mi);
	}return 0;
} 
