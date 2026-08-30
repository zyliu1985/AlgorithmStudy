#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[100010];
int ans[100010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=INT_MAX;
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i,now=0;
		while(l-1>=1 && r+1<=n){
			l--; r++;
			now+=abs(a[l]-a[r]);
			ans[r-l+1]=min(ans[r-l+1],now);
		}
	}
	ans[1]=0;
	for(int i=1;i<=n-1;i++){
		int l=i,r=i+1,now=abs(a[l]-a[r]);
		ans[2]=min(ans[2],now);
		while(l-1>=1 && r+1<=n){
			l--,r++;
			now+=abs(a[l]-a[r]);
			ans[r-l+1]=min(ans[r-l+1],now);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}
