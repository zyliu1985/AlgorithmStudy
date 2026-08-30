#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
typedef long long ll;
int main(){
	ll n;
	scanf("%lld",&n);
	std::vector<ll>h(n);
	for(auto&i:h){
		scanf("%lld",&i);
	}
	std::vector<ll>ans;
	for(ll i=1;i<=n;i++){
		ll nans=LLONG_MAX;
		for(ll s=0;s<=n-i;s++){
			ll e=s+i-1;
			ll now=0;
			for(ll j=s,k=e;j<=k;j++,k--){
				now+=std::abs(h[j]-h[k]);
			}
			nans=std::min(nans,now);
		}
		ans.push_back(nans);
	}
	for(auto&i:ans){
		printf("%lld ",i);
	}
	return 0;
}
//ʱ�䣺O(n^2) �ռ䣺O(n) 
