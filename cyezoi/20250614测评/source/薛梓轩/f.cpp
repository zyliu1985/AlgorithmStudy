#include<bits/stdc++.h>//go for 20 percent pts
using namespace std;
#define int long long
int n,m,a[3100],b,c[4000],ci,ai,ans=LLONG_MIN;
void slove(int pos,int last,int dp){
	if(pos==n+5){
		ans=max(ans,dp);
		return;
	}
	if(last==0)slove(pos+1,1,dp+a[pos]);
	slove(pos+1,0,dp);
}
void slove2(int pos,int last,int dp){
	if(pos==n+5){
		ans=max(ans,dp);
		return;
	}
	if(last==0)slove(pos+1,1,dp+c[pos]);
	slove(pos+1,0,dp);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	if(m==0)slove(1,0,0);
	if(m==1){
		cin>>b;
		for(int i=0;i<=n;i++){
			memset(c,0,sizeof c);
			for(int i=1;i<=n;i++)c[i]=a[i];
			c[i+1]=b;
			slove2(1,0,0);
		}
	}
	cout<<ans;
	return 0;
}
