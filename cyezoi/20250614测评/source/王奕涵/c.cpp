#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=INT_MAX;
int h[5001],hh[5001];
void dfs(int m,int l,int r,long long cnt){
	for(int i=l;i<=r;i++){
		hh[++cnt]=h[i];
	}
	cnt=0;
	for(int i=1;i<=m/2;i++){
		cnt+=abs(hh[i]-hh[m-i+1]);
		if(cnt>=ans)break;
	}
	ans=min(ans,cnt);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	cout<<0<<" ";
	for(int i=2;i<n;i++){
		ans=INT_MAX;
		for(int l=1;l<=n-i+1;l++){
			int r=l+i-1;
			dfs(i,l,r,0);
		}
		cout<<ans<<" ";
	}
	ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=abs(h[i]-h[n-i+1]);
	}
	cout<<ans;
	return 0;
}
