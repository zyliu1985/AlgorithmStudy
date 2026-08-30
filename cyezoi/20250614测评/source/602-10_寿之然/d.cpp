#include <bits/stdc++.h>
using namespace std;
int n,m;
int vis[100010];
int main( ){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		for(int j=x;j>=1;j--){
			if(vis[j]==0){
				vis[j]=1;
				break;
			}
			if(j==1){
				int ans=0;
				for(int k=0;k<=n;k++)
					ans+=vis[k];
				cout<<ans;
				return 0;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans+=vis[i];
	cout<<ans;
	return 0;
}
