#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[5005],odd[5005],even[5005],hmin,ans[5005];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>h[i];
	}
	for(ll i=1;i<(ll)ceil(n/2.0);i++){
		hmin=1e18;
		for(ll j=i+1;j<=n-i;j++){
			odd[j]+=abs(h[j-i]-h[j+i]);
			hmin=min(hmin,odd[j]);
		}
		ans[2*i+1]=hmin;
	}
	for(ll i=1;i<=n/2;i++){
		hmin=1e18;
		for(ll j=i;j<=n-i;j++){
			even[j]+=abs(h[j-i+1]-h[j+i]);
			hmin=min(hmin,even[j]);
		}
		ans[2*i]=hmin;
	}
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

