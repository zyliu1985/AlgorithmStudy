#include<bits/stdc++.h>
using namespace std;

int c,total,ans=0;
char a[2][200000];
int vis[2][200000];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1}; 

void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && nx<2 && ny>=0 && ny<c && vis[nx][ny]==0 && a[nx][ny]!='0'){
			vis[nx][ny]=1;
			total++;
			dfs(nx,ny);
		}
	}
}

int main(){
	cin>>c;
	for(int i=0;i<2;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]=='1' && vis[i][j]==0){
				vis[i][j]=1;
				total=1;
				dfs(i,j);
				ans+=total*3-(total-1)*2;
			}
		}
	}
	cout<<ans;
} 
