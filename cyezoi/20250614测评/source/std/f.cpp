#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e3+10;
int n,m,ans,a[N],b[105],f[2][105][105][2];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++) {
		int now=i&1,pre=now^1;
		for(int j=0;j<=m;j++) {
			for(int k=0;k<=j;k++) {
				f[now][j][k][0]=max(f[pre][j][k][1],f[pre][j][k][0]);
				f[now][j][k][1]=f[pre][j][k][0]+a[i];
				if(j&&k) f[now][j][k][0]=max(f[now][j][k][0],f[pre][j-1][k-1][0]+b[m-k+1]);
				if(j-1>=k) f[now][j][k][1]=max(f[now][j][k][1],f[pre][j-1][k][1]+a[i]);
				ans=max(ans,max(f[now][j][k][0],f[now][j][k][1]));
			} 
		}
	}
	for(int i=n+1;i<=n+m;i++) {
		int now=i&1,pre=now^1;
		for(int j=0;j<=m;j++) {
			for(int k=0;k<=j;k++) {
				if(j) f[now][j][k][0]=max(f[pre][j-1][k][1],f[pre][j-1][k][0]);
				if(j&&k) f[now][j][k][1]=f[pre][j-1][k-1][0]+b[m-k+1];
				ans=max(ans,max(f[now][j][k][0],f[now][j][k][1]));
			} 
		}
	}
	cout<<ans<<"\n";		
	return 0;
} 
/*
# P9814 2015S5 dp

*/

