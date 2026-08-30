#include<bits/stdc++.h>
using namespace std;
int n,ret,a[10][200010],vis[10][200010];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int dx1[10]={0,0};
int dy1[10]={1,-1};
struct node{
	int x,y;
};
void bfs(int i,int j){
	queue<node>q;
	vis[i][j]=1;
	q.push((node){i,j});
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int nx=now.x,ny=now.y,cnt=0;
		if(ny%2==0){
			for(int i=0;i<2;i++){
				int xx=nx+dx1[i],yy=ny+dy1[i];
				if(xx>=1&&xx<=2&&yy>=1&&yy<=n){
					if(a[xx][yy]==1){
						cnt++;
						if(vis[xx][yy]==0){
							vis[xx][yy]=1;
							q.push((node){xx,yy});
						}
					}
				}
			}
		}else{
			for(int i=0;i<4;i++){
				int xx=nx+dx[i],yy=ny+dy[i];
				if(xx>=1&&xx<=2&&yy>=1&&yy<=n){
					if(a[xx][yy]==1){
						cnt++;
						if(vis[xx][yy]==0){
							vis[xx][yy]=1;
							q.push((node){xx,yy});
						}
					}
				}
			}
		}ret+=(3-cnt);
	}
}int main(){
	scanf("%d",&n);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1&&vis[i][j]==0){
				bfs(i,j);
			}
		}
	}printf("%d",ret);
	return 0;
} 
