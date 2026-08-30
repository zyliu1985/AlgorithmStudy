#include<bits/stdc++.h>
#define N 5005
#define INF 1e18
typedef long long ll;
using namespace std;
ll n,h[N],ans[N];
void pts_33(){
	fill(ans,ans+N,INF);
	ans[1]=0;
	for(ll k=2;k<=n;k+=2)
		for(ll i=k/2;i<=n-k/2;i++){
			ll t=0;
			for(ll j=0;j<=k/2-1;j++)
				t+=labs(h[i+j+1]-h[i-j]);
			ans[k]=min(ans[k],t);
		}
	for(ll k=3;k<=n;k+=2)
		for(ll i=(k+1)/2;i<=n-(k+1)/2+1;i++){
			ll t=0;
			for(ll j=0;j<=(k+1)/2-1;j++)
				t+=labs(h[i+j]-h[i-j]);
			ans[k]=min(ans[k],t);
		}
	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
}
bool ex2(){
	for(ll i=2;i<=n;i++) if(h[i]<h[i-1]) return false;
	return true;
}
void pts_66(){
	;
}
void pts_100(){
	;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>h[i];
	if(n<=300) pts_33();
	else if(ex2()) pts_66();
	else pts_100();
	return 0;
}
