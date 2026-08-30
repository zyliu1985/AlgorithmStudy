#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=n-1;i>0;--i){
		f[i][2]=abs(a[i]-a[i+1]);
		for(int j=3;j<=n-i+1;++j)
			f[i][j]=abs(a[i]-a[i+j-1])+f[i+1][j-2];
	}
	for(int i=1;i<=n;++i){
		int minn=2e9;
		for(int j=1;j<=n-i+1;++j)
			minn=min(minn,f[j][i]);
		cout<<minn<<' ';
	}
	return 0;
}

