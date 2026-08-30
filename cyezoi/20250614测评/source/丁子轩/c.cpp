#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int h[5010];
int ans[5010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		int len=1;
		int l=i,r=i;
		int now=0;
		ans[len]=min(ans[len],now);
		while(1){
			l--;
			r++;
			len+=2;
			if(!(l>=1&&r<=n))break;
			now+=abs(h[r]-h[l]);
			ans[len]=min(ans[len],now);
		}
	}
	for(int i=1;i<n;i++){
		int len=2;
		int l=i,r=i+1;
		int now=abs(h[r]-h[l]);
		ans[len]=min(ans[len],now);
		while(1){
			l--;
			r++;
			len+=2;
			if(!(l>=1&&r<=n))break;
			now+=abs(h[r]-h[l]);
			ans[len]=min(ans[len],now);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}
