#include<bits/stdc++.h>
using namespace std;
int arr[3][200005];
int visited[3][200005],n,cnt;
int dx[5]={-1,0,1,0};
int dy[5]={0,1,0,-1};
void dfs(int x,int y)
{
	int tx,ty,i;
	for(i=0;i<4;++i)
	{
		tx=x+dx[i];
		ty=y+dy[i];
	//	printf("%d %d\n",tx,ty);
		if(tx>2||tx<1||ty<1||ty>n||visited[tx][ty]||arr[tx][ty]==0)
			continue;
		cnt++;
		visited[tx][ty]=1;
		dfs(tx,ty); 
	}
}
int main()
{
	int i,j,ans=0;
	scanf("%d",&n);
	memset(visited,0,sizeof(visited));
	for(i=1;i<=2;++i)
	{
		for(j=1;j<=n;++j)
			scanf("%d",&arr[i][j]);
	}
	for(i=1;i<=2;++i)
	{
		for(j=1;j<=n;++j)
		{
			
			if(arr[i][j]==1&&visited[i][j]==0)
			{
				visited[i][j]=1;
				cnt=1;
				dfs(i,j);
				if(cnt==2*n)
				{
					ans=n/2*2+4;
					printf("%d",ans);
					return 0;
				}
				ans=ans+3+cnt-1;
//				printf("%d\n",cnt);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
