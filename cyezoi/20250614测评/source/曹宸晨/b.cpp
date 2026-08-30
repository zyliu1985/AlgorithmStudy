#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[2][N],ans;
bool vis[2][N];
void bfs(int x,int y)
{
	queue < pair<int,int> > q;
	q.push({x,y}); vis[x][y] = false;
	while(!q.empty())
	{
		int x = q.front().first,y = q.front().second; q.pop();
		for(int i = -1; i <= 1; i+= 2)
		{
			int nx = x;
			int ny = y + i;
			if(ny < 1 || ny > n)
			{
				ans++;
				continue;
			}
			if(!a[nx][ny])
			{
				ans++;
				continue;
			}
			if(!vis[nx][ny]) continue;
			vis[nx][ny] = false;
			q.push({nx,ny});
		}
		if((x + y) % 2)
		{
			int nx = x - 1,ny = y;
			if(nx < 1)
			{
				ans++;
				continue;
			}
			if(!a[nx][ny])
			{
				ans++;
				continue;
			}
			if(!vis[nx][ny]) continue;
			vis[nx][ny] = false;
			q.push({nx,ny});
			continue;
		}
		else
		{
			int nx = x + 1,ny = y;
			if(nx > n)
			{
				ans++;
				continue;
			}
			if(!a[nx][ny])
			{
				ans++;
				continue;
			}
			if(!vis[nx][ny]) continue;
			vis[nx][ny] = false;
			q.push({nx,ny});
			continue;
		}
	}
}
signed main()
{
	scanf("%d",&n);
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d",&a[i][j]);
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= n; j++)
			vis[i][j] = a[i][j];
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= n; j++)
			if(vis[i][j]) bfs(i,j);
	printf("%d",ans);
}
