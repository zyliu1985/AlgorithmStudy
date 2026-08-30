#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;

bool col[3][N];
int c, ans;

int main()
{
	cin >> c;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= c; j++)
			cin >> col[i][j];
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= c; j++)
		{
			if (!col[i][j])	continue;
			if (i == 1 && j % 2 == 0)
			{
				ans += 3;
				if (col[i][j - 1])	ans--;
				if (col[i][j + 1])	ans--;
			}
			if (i == 1 && j % 2 == 1)
			{
				ans += 3;
				if (col[i][j - 1])	ans--;
				if (col[i][j + 1])	ans--;
				if (col[i + 1][j])	ans--;
			}
			if (i == 2 && j % 2 == 0)
			{
				ans += 3;
				if (col[i][j - 1])	ans--;
				if (col[i][j + 1])	ans--;
			}
			if (i == 2 && j % 2 == 1)
			{
				ans += 3;
				if (col[i][j - 1])	ans--;
				if (col[i][j + 1])	ans--;
				if (col[i - 1][j])	ans--;
			}
		}
	cout << ans << endl;
	return 0;
}
