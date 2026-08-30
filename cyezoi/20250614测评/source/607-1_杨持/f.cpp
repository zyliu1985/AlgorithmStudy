#include<bits/stdc++.h>
#define N 3110
using namespace std;
int n,m;
int a[N],b[N];
int f[N][2];
int ans;
inline int solve(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=f[i-1][0]+a[i];
	}
	return max(f[n][0],f[n][1]);
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	if(m==1){
		for(int i=n;i;i--)swap(a[i],a[i+1]);
		a[1]=b[1];
		n++;
		for(int i=1;i<=n;i++){
			ans=max(ans,solve());
			swap(a[i],a[i+1]);
		}
	}
	else ans=solve();
	printf("%d",ans);
}

