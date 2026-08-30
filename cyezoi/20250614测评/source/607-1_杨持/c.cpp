#include<bits/stdc++.h>
#define N 5010
using namespace std;
int n;
int h[N];
int ans[N];
inline void solve(int l,int r){
	int res=0;
	for(;l>=1&&r<=n;l--,r++){
		res+=abs(h[l]-h[r]);
		ans[r-l+1]=min(ans[r-l+1],res); 
	}
}
signed main(){
	memset(ans,0x7f,sizeof(ans));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++){
		solve(i,i);
		if(i!=n)solve(i,i+1);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}

