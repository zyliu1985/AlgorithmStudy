#include<bits/stdc++.h>
using namespace std;

int c;
long long ans;
int a[200009][4];
bool jd[200009][4];



int x[6] = {1, 0, -1, 1, 0, -1};
int y[6] = {1, 1, 1, -1, -1, -1};

void bfs(int x1, int y1)
{
	if (jd[x1][y1] == 0)
	{
		return;
	}
	ans += 3;
	for (int i = 0; i < 6; i++)
	{
		int xx = x1 + x[i], yy = y1 + y[i];
		if (xx > 4 || yy > 4 || xx < 0 || yy < 0)
		{
			continue;
		}
		if (a[xx][yy] == 1) ans--;
	}
	jd[x1][y1] = 0;
	for (int i = 0; i < 6; i++)
	{
		int xx = x1 + x[i], yy = y1 + y[i];
		if (xx > 4 || yy > 4 || xx < 0 || yy < 0)
		{
			continue;
		}
		bfs(xx, yy);
		
	}
	return;
}

int main()
{
	cin >> c;
	for (int i = 0, k; i < c; i++)
	{
		cin >> k;
		a[i][(i + 1) % 2] = k;
		if (a[i][(i + 1) % 2] == 1)
			jd[i][(i + 1) % 2] = 1;
	}
	for (int i = 0, k; i < c; i++)
	{
		cin >> k;
		a[i][(i + 1) % 2 + 2] = k;
		if (a[i][(i + 1) % 2 + 2] == 1)
			jd[i][(i + 1) % 2 + 2] = 1;
	}
//	for (int i = 0; i <= 4; i++)
//	{
//		for (int j = 0; j < c; j++)
//			cout << jd[j][i] << " ";
//		cout << endl;
//	}
	for (int i = 0; i <= c; i++)
	{
		for (int j = 0; j < 4; j++)
			if (jd[i][j] == 1)
			{
				bfs(i, j);
				cout << ans << " " << i << " " << j << "\n";
			}
	}
	cout << ans;
	return 0;
}
