#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5010;
int n;
int a[N];
int ans[N];

signed main(){
//	freopen("data.in","r",stdin);
//	freopen("data.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1e18;
	}ans[1]=0;
	for(int i=2;i<n;i++){
		int now=0,l=1;
		for(int j=1;j<=n;j++){
			if(i-j<1||i+j>n) break;
			l+=2;
			now+=abs(a[i+j]-a[i-j]);
			if(now<ans[l]) ans[l]=now;
		}
	}
	for(int i=2;i<=n;i++){
		int now=0,l=0;
		for(int j=1;j<=n;j++){
			if(i-j<1||i+j-1>n) break;
			l+=2;
			now+=abs(a[i+j-1]-a[i-j]);
			if(now<ans[l]) ans[l]=now;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
