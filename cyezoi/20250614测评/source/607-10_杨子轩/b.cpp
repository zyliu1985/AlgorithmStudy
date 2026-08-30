#include<bits/stdc++.h>
using namespace std;

int c;
int a[2][200010];int ans;
bool vis[2][200010];

int dx[10],dy[10];

void dxxy(int i,int j){
	if(i==1&&j%2==0){
		dx[0]=0;dx[1]=0;dx[2]=-1;
		dy[0]=-1;dy[1]=1;dy[2]=0;
	}
	if(i==1&&j%2==1){
		dx[0]=0;dx[1]=0;dx[2]=1;
		dy[0]=-1;dy[1]=1;dy[2]=0;
	}
	if(i==2&&j%2==1){
		dx[0]=0;dx[1]=0;dx[2]=-1;
		dy[0]=-1;dy[1]=1;dy[2]=0;
	}
	if(i==2&&j%2==0){
		dx[0]=0;dx[1]=0;dx[2]=1;
		dy[0]=-1;dy[1]=1;dy[2]=0;
	}
}

void dfs(int i,int j){

	for(int k=0;k<3;k++){dxxy(i,j);
		int nx=i+dx[k];int ny=j+dy[k];
//		cout<<vis[nx][ny]<<" "<<i<<" "<<nx<<" "<<ny<<" "<<ans<<endl;
		if(nx<=2&&nx>=1&&ny>=1&&ny<=c&&a[nx][ny]==1&&vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny);
			
		}
		else if(!vis[nx][ny]){
			ans++;		
		}
//		cout<<i<<" "<<j<<endl;
//		cout<<nx<<" "<<ny<<endl;
//cout<<ans<<endl;
	}
}

int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.ans","w",stdout);
	cin>>c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			if(!vis[i][j]&&a[i][j]==1){
				vis[i][j]=1;dfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
