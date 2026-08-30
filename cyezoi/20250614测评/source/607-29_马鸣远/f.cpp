#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[3005],b[105],f[3005],g[3005][2],h[3005][105],bs[105];
int main(){
	cin>>n;
	n+=2;
	for(ll i=2;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(ll i=1;i<=m;i++){
		cin>>b[i];
	}
	if(m==0){
		for(ll i=2;i<=n;i++){
			f[i]=max(f[i-1],f[i-2]+a[i]);
		}
		cout<<f[n];
	}
	else if(m==1){
		for(ll i=2;i<=n;i++){
			g[i][0]=max(g[i-1][0],g[i-2][0]+a[i]);
			g[i][1]=max(max(g[i-1][0]+a[i],g[i-2][0]+b[1]),max(g[i-1][1],g[i-2][1]+a[i]));
			//cout<<g[i][0]<<" "<<g[i][1]<<endl;
		}
		cout<<max(g[n][0],g[n][1]);
	}
	/*else{
		sort(b+1,b+n+1);
		for(ll i=1;i<=m;i++){
			bs[i]=bs[i-1]+b[i];
		}
		for(ll i=2;i<=n;i++){
			for(ll j=0;j<=m;j++){
				h[i][j]=max(h[i-1][j],h[i-2][j]+a[i]);
				for(ll k=1;k<=j;k++){
					if(k&1){
						h[i][j]=max(h[i][j],max(h[i-1][j-k]+(bs[j]-bs[j-k/2])+a[i],h[i-2][j-k]))
					}
					else{
						
					}
				}
			}
		}
	}*/
	return 0;
}

