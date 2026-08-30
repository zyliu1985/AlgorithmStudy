#include <bits/stdc++.h>
using namespace std;

const int N=200010;

int n,cnt,t,ans,mp[3][N],vis[3][N];
int sx,sy;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct u{
	int x,y;
};
queue<u>q;

void bfs(){
	q.push(u{sx,sy});
	vis[sx][sy]=1;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y;
		q.pop();
		for(int i=0;i<4;++i){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx<1||tx>2||ty<1||ty>n)
				continue; 
			if((i==1&&x==1&&y%2==0) || (i==0&&x==2&&y%2==0))
				continue; 
			if(mp[tx][ty]){
				++t;
				if(vis[tx][ty])
					continue;
				++cnt;
				vis[tx][ty]=1;
				q.push(u{tx,ty});
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=2;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&mp[i][j]);
	for(int i=1;i<=2;++i)
		for(int j=1;j<=n;++j)
			if(mp[i][j]==1 && vis[i][j]==0){
				cnt=1;
				t=0;
				sx=i,sy=j;
				bfs();
				ans+=cnt*3-t;
			}
	printf("%d",ans);
	return 0;
}
