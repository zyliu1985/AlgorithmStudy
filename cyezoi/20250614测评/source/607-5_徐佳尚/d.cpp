#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll g,n,t[N];
ll lowbit(ll x){
	return x&(-x);
}
void upd(ll x){
	for(;x<=n;x+=lowbit(x)){
		t[x]++;
	}
}
ll qry(ll x){
	ll sum=0;
	for(;x;x-=lowbit(x)){
		sum+=t[x];
	}
	return sum;
}
int main(){
	scanf("%lld%lld",&g,&n);
	bool flag=0;
	ll ans=n;
	for(ll i=1;i<=n;i++){
		ll a;
		scanf("%lld",&a);
		if(qry(a)>=a && flag==0){
			flag=1;
			ans=i-1;
		}
		upd(a);
	}
	printf("%lld\n",ans);
	return 0;
}
