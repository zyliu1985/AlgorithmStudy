#include<bits/stdc++.h>
using namespace std;
int g,p,max_=-1;
int a[100005],vis[100005];
void dfs(int plane) {
	bool find=false;
	for(int i=0; i<a[plane]; i++) {
		if(vis[i]==0) {
			find=true;
			vis[i]=1;
			dfs(plane+1);
			vis[i]=0;
		}
	}
	if(!find) {
		max_=max(max_,plane);
	}
}
int main() {
	cin>>g>>p;
	for(int i=0; i<p; i++) {
		cin>>a[i];
		vis[i]=0;
	}
	dfs(0);
	cout<<max_;
	return 0;
}
