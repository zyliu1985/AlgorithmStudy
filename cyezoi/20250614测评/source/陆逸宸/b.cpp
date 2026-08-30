#include <bits/stdc++.h>
using namespace std;
long long n,ans,mp[2][200010],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool vis[2][200010];
int dfs(int x,int y){
	int z=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		//cout<<nx<<ny<<i<<"y";
		if(nx>=1 && nx<=2 && ny>=1 && ny<=n && mp[nx][ny]==1 && vis[nx][ny]!=1){
			vis[nx][ny]=1;
			//cout<<nx<<ny<<"ok";
			z+=dfs(nx,ny);
		}else{
			//cout<<nx<<ny<<' ';
		}
	}
	return z;
}
int main(){
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==1 && vis[i][j]!=1){
				vis[i][j]=1;
				ans+=dfs(i,j)+2;
			}
		}
	}
	cout<<ans;
	return 0;
}
