#include<bits/stdc++.h>
using namespace std;
#define int long long
int c;
string s[10];
bool vis[3][100010];
bool in(int x,int y){
	return x>=1&&x<=2&&y>=1&&y<=c;
}
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int x,int y){
	int siz=1;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(!in(tx,ty))continue;
		if(vis[tx][ty])continue;
		if(s[tx][ty]=='0')continue;
		siz+=dfs(tx,ty);
	}
	return siz;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	for(int i=1;i<=2;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	int ans=0;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			if(s[i][j]=='0')continue;
			if(!vis[i][j]){
				ans+=dfs(i,j)+2;
			}
		} 
	}
	cout<<ans;
}
