#include <bits/stdc++.h>
using namespace std;

const int N=5010;

int n,ans,sum,a[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		ans=INT_MAX;
		for(int l=1;l+i-1<=n;++l){
			int r=l+i-1;
			sum=0;
			for(int k=0;k<=(r-l)/2;++k)
				sum+=abs(a[l+k]-a[r-k]);
			ans=min(ans,sum);
		}
		printf("%d ",ans);
	}
	return 0;
}
