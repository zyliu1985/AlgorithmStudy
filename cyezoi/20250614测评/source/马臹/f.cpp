#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
typedef long long ll;
ll n,m,ans=LLONG_MIN;
std::vector<ll>a,b;
void dfs(ll x){
	if(x==b.size()){
		ll sum=0;
		for(ll i=0;i<a.size();i+=2){
			sum+=a[i];
		}
		ans=std::max(ans,sum);
		return;
	}
	for(auto it=a.begin();it!=a.end()+1;it++){
		it=a.insert(it,b[x]);
		dfs(x+1);
		a.erase(it);
	}
}
int main(){
	scanf("%lld",&n);
	a.resize(n);
	for(auto&i:a){
		scanf("%lld",&i);
	}
	scanf("%lld",&m);
	b.resize(m);
	for(auto&i:b){
		scanf("%lld",&i);
	}
	dfs(0);
	printf("%lld",ans);
	return 0;
}
//ʱ�䣺O(nm) �ռ䣺O(n) 
