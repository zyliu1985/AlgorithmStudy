#include<bits/stdc++.h>
using namespace std;
int n,m,a[3500],b[150],f[4000],va[3500];
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	cin>>m;for(int i=0;i<m;i++)cin>>b[i];
	if(m==0){
		for(int i=3;i<n+3;i++){
			f[i]=max(max(f[i-2],f[i-3])+a[i-3],f[i-1]);
		}cout<<f[n+2];
	}int mx=0;
	if(m==1){
		for(int i=0;i<n;i++){
			for(int j=0,jj=0;j<=n;j++){
				if(i!=j)va[j]=a[jj++];
				else va[j]=b[0];
			}
			for(int j=3;j<n+4;j++){
				f[j]=max(max(f[j-2],f[j-3])+va[j-3],f[j-1]);
			}if(f[n+3]==17)cout<<i<<endl;
			mx=max(mx,f[n+3]);
		}cout<<mx;
	}
	return 0;
}
