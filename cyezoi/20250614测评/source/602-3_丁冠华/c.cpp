#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,a[5050],ans[5050];
int main(){
	memset(ans,0x3f,sizeof(ans));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;i-j>0&&i+j<=n;j++){
			cnt+=abs(a[i+j]-a[i-j]);
			ans[2*j+1]=min(ans[2*j+1],cnt);
		}
	}
	for(int i=1;i<n;i++){
		int cnt=0;
		for(int j=1;i-j+1>0&&i+j<=n;j++){
			cnt+=abs(a[i-j+1]-a[i+j]);
			ans[2*j]=min(ans[2*j],cnt);
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
