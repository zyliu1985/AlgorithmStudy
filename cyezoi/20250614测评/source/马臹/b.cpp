#include<cstdio>
#include<vector>
typedef long long ll;
int main(){
	ll c;
	scanf("%lld",&c);
	std::vector<std::vector<ll>>m(2,std::vector<ll>(c));
	for(auto&i:m){
		for(auto&j:i){
			scanf("%lld",&j);
		}
	}
	ll ans=0;
	for(ll i=0;i<2;i++){
		for(ll j=0;j<c;j++){
			if(m[i][j]){
				ans+=3;
				if(j!=0&&m[i][j-1]){
					ans-=2;
				}
				if(i!=0&&(i&1)&&m[i-1][j]){
					ans-=2;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
//ʱ�䣺O(c) �ռ䣺O(c) 
