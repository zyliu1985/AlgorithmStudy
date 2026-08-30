#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5;
ll n,a[N],ans[N];
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ans[i]=0x3f3f3f3f3f3f3f3f;
	}
	for(ll m=1;m<=n;m++){
		ll sum=0;
		for(ll len=0;m-len>=1 && m+len<=n;len++){
			sum+=abs(a[m+len]-a[m-len]);
			ans[2*len+1]=min(ans[2*len+1],sum);
		}
	}
	for(ll m=2;m<=n;m++){
		ll sum=0;
		for(ll len=0;m-1-len>=1 && m+len<=n;len++){
			sum+=abs(a[m-1-len]-a[m+len]);
			ans[2*len+2]=min(ans[2*len+2],sum);
		}
	}
	for(ll i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
