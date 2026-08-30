#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+5,M=105;
ll n,m,a[N],b[M],f[N][2];
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	if(m==0){
		f[1][1]=a[1];
		f[1][0]=0;
		for(ll i=2;i<=n;i++){
			f[i][0]=max(f[i-1][1],f[i-1][0]);
			f[i][1]=f[i-1][0]+a[i];
		}
		printf("%lld\n",max(f[n][0],f[n][1]));
		return 0;
	}
	if(m==1){
		ll ans=0;
		for(ll i=1;i<=n+1;i++){
			if(i==1){
				f[1][1]=b[1];
				f[1][0]=0;
			}
			else{
				f[1][1]=a[1];
				f[1][0]=0;
			}
			for(ll j=2;j<=n+1;j++){
				ll x;
				if(j==i)x=b[1];
				else if(j>i)x=a[j-1];
				else x=a[j];
				f[j][0]=max(f[j-1][1],f[j-1][0]);
				f[j][1]=f[j-1][0]+x;
			}
			ans=max(ans,max(f[n][0],f[n][1]));
		}
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}
