#include<bits/stdc++.h>
using namespace std;
int vis[3005];
int main(){
	int n,m;
	cin>>n>>m;
	if(m==0){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-2;i++){
			if(!vis[i]&&!vis[i+1]&&!vis[i+2]){
				if(a[i]>=a[i+1]&&a[i]>=a[i+2]){
					vis[i]=1;
				}
				else if(a[i+1]>=a[i]&&a[i+1]>=a[i+2]){
					vis[i+1]=1;
				}
				else{
					vis[i+2]=1;
				}
			}
		}
		if(vis[1]==0){
			vis[0]=1;
		}
		if(vis[n-2]==0){
			vis[n-1]=1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(vis[i]){
				ans+=a[i];
			}
		}
		cout<<ans;
	}
	return 0;
}

