#include<bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;
ll n,m,x[N],f[N];
ll find(ll x){ return f[x]==x?x:f[x]=find(f[x]); }
int main(){
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>x[i];
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		ll t=find(f[x[i]]);
		if(t<1){
			cout<<i-1;
			return 0;
		}
		f[x[i]]--;
	}
	return 0;
}
