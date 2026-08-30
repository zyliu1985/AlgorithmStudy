#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,a[N],b[N],cnt;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)cnt+=3;
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		if(b[i]==1)cnt+=3;
	}
	for(ll i=2;i<=n;i++){
		if(a[i]==1 && a[i-1]==1)cnt-=2;
	}
	for(ll i=2;i<=n;i++){
		if(b[i]==1 && b[i-1]==1)cnt-=2;
	}
	for(ll i=1;i<=n;i+=2){
		if(a[i]==1 && b[i]==1)cnt-=2;
	}
	printf("%lld\n",cnt);
	return 0;
}
