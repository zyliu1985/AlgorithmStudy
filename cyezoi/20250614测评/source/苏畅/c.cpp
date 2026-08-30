#include<bits/stdc++.h>//sc
#define ll long long
using namespace std;
ll n,a[5050],d[5005][5005],ans[5050];
int main(){
	memset(ans,0x7f,sizeof(ans));
	ans[1]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1,j=k;j<=n;i++,j++){
			d[i][j]=d[i+1][j-1]+abs(a[i]-a[j]);
			ans[k]=min(ans[k],d[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
