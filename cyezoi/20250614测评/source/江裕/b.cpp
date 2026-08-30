#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int n, a[N][5], vis[N][5], SCC, jian, ans;
int dx[] = {-1, 0, 1};
int dy[] = {0, 1, 0};

void dfs(int x, int y)
{
//	cout << x << " " << y << "\n";
	for(int i = 0; i < 3; i ++ )
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
//		cout << x << " " << y << " " << nx << " " << ny << " " << jian << "\n";
		if(nx < 1 || nx > n || ny < 1 || ny > 2 || vis[nx][ny] || !a[nx][ny]) continue;
		vis[nx][ny] = vis[x][y];
		jian ++ ;
		dfs(nx, ny);
	}
	return;
}

int main()
{
	cin >> n;
	bool flag = true;
	for(int i = 1; i <= n; i ++ )
	{
		 cin >> a[i][1];
		 ans += a[i][1];
		 if(!a[i][1]) flag = false;
	}
	for(int i = 1; i <= n; i ++ ){
		
		cin >> a[i][2];
		ans += a[i][2];
		if(!a[i][2]) flag = false;
	}
	if(flag)
	{
		cout << n + 3;
		return 0;
	}
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= 2; j ++ )
		{
			
			if(!vis[i][j] && a[i][j])
			{
//				cout << i << " " << j << " " << a[i][j] << "\n";
				vis[i][j] = ++ SCC;
				dfs(i, j);
//				puts("");
			}
		}
	}
	cout << ans * 3 - jian * 2;
	return 0;
}
