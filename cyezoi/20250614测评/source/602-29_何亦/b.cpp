#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+3;
bool vis[5][maxn];
int nums[5][maxn],n;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int dfs(int x,int y){
	vis[x][y]=true;
	int siz=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(nx<1 || nx>2 || ny<1 || ny>n)continue;
		if(!vis[nx][ny] && nums[nx][ny]==1){
			siz+=dfs(nx,ny);
		}
	}
	return siz;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>nums[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j] && nums[i][j]==1){
				ans+=dfs(i,j)+2;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/
