#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010][5010],ans[5010];
int main(){
	memset(ans,0x3f,sizeof(ans));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans[1]=0;
	for(int i=1;i<n;i++)b[i][2]=abs(a[i]-a[i+1]),ans[2]=min(ans[2],b[i][2]);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++)b[j][i]=abs(a[j]-a[j+i-1])+b[j+1][i-2],ans[i]=min(ans[i],b[j][i]);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
