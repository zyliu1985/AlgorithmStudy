#include <iostream>
using namespace std;

const int N=4e5+5;

const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,1,-1};

int n,cnt,res,a[2][200005];
bool vis[5][N];

void dfs(int x,int y)
{
	vis[x][y]=1;
	cnt++;
	
	for (int i=1;i<=4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		
		if (1<=xx && xx<=2 && 1<=yy && yy<=n && !vis[xx][yy] && a[xx][yy])
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (!vis[i][j] && a[i][j])
			{
				cnt=0;
				dfs(i,j);
				res+=cnt+2;
			}
		}
	}
	
	cout << res;
	return 0;
}

// DFS,联通块，胶带是2+cnt
 
