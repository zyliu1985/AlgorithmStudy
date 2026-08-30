#include<bits/stdc++.h>
using namespace std;

int n,m,c[3330],f[5000];

int dp(int a){
	if(f[a]!=0) return f[a];
	if(a<=0) return 0;
	f[a]=max(dp(a-2),dp(a-3))+c[a];
	return f[a];
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>c[i+n];
	f[1]=c[1];
	f[2]=c[2];
	cout<<max(dp(m+n),dp(m+n-1));
	return 0;
}
