#include <bits/stdc++.h>
using namespace std;
//#define int ll
#define ll long long
int n,a[5005],f[5005][5005],ans;
signed main(){
	cin>>n;
	if(n==1){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(f,0x3f,sizeof(f));ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)f[1][i]=0;
	for(int i=1;i<n;i++)f[2][i]=abs(a[i]-a[i+1]),ans=min(ans,f[2][i]);
	cout<<"0 "<<ans;
	
	for(int i=3;i<=n;i++){
		ans=0x3f3f3f3f;
		for(int j=1;j<=n-i+1;j++){
			f[i][j]=f[i-2][j+1]+abs(a[j]-a[j+i-1]);
			ans=min(ans,f[i][j]);
		}
		cout<<' '<<ans;
	}
	cout<<'\n';
	
	return 0;
}
