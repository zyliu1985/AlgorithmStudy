#include <bits/stdc++.h>
using namespace std;

int n, maxn = -INT_MAX;
int cnt[10];
char a[100010][10];
queue<int> q;

int main(void)
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= 5;j ++)
			cin >> a[i][j];	
	
	for(int i = 1;i <= 5;i ++)
	{
		for(int j = 1;j <= n;j ++)
			if(a[j][i] == 'Y')
				cnt[i] ++;
		maxn = max(maxn, cnt[i]);
	}
	
	for(int i = 1;i <= 5;i ++)
		if(cnt[i] == maxn)
			q.push(i);
	
	while(!q.empty())
	{
		cout << q.front();
		q.pop();
		if(!q.empty())
			cout << ",";
	}
	return 0;
}

/*
3 
YY.Y. 
...Y. 
.YYY.

5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/
