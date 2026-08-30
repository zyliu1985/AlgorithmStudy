#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll G,P,g,bit[100005];
ll LSB(ll x){
	return x&(-x);
}
void add(ll x,ll d){
	for(ll i=x;i<=G;i+=LSB(i)){
		bit[i]+=d;
	}
}
ll psq(ll x){
	ll ans=0;
	for(ll i=x;i;i-=LSB(i)){
		ans+=bit[i];
	}
	return ans;
}
ll rsq(ll l,ll r){
	return psq(r)-psq(l-1);
}
ll search(ll l,ll r){
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(rsq(mid,r)<r-mid+1){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>G>>P;
	for(ll i=1;i<=P;i++){
		cin>>g;
		ll pos=search(1,g);
		if(!pos){
			cout<<i-1;
			return 0;
		}
		add(pos,1);
	}
	cout<<P;
	return 0;
}

