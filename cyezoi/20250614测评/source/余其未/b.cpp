#include<bits/stdc++.h>
#define N 200005
typedef long long ll;
using namespace std;
ll n,ans,a[10][N],x[3][N];
int main(){
	cin>>n;
	for(ll i=1;i<=2;i++){
		for(ll j=1;j<=n;j++) cin>>x[i][j];
		for(ll j=1;j<=n;j++) if(x[i][j]){
			if(i==1){
				if(j%2==1){
					a[2][j]=(a[2][j]==1?0ll:1ll);
					a[2][j+1]=(a[2][j+1]==1?0ll:1ll);
					a[3][j]=(a[3][j]==1?0ll:1ll);
				}
				else{
					a[1][j]=1;
					a[2][j]=(a[2][j]==1?0ll:1ll);
					a[2][j+1]=(a[2][j+1]==1?0ll:1ll);
				}
			}
			else{
				if(j%2==0){
					a[4][j]=(a[4][j]==1?0ll:1ll);
					a[4][j+1]=(a[4][j+1]==1?0ll:1ll);
					a[5][j]=1;
				}
				else{
					a[3][j]=(a[3][j]==1?0ll:1ll);
					a[4][j]=(a[4][j]==1?0ll:1ll);
					a[4][j+1]=(a[4][j+1]==1?0ll:1ll);
				}
			}
		}
	}
	for(ll i=1;i<=5;i++) for(ll j=1;j<=n+1;j++) ans+=a[i][j];
	cout<<ans;
	return 0;
}
