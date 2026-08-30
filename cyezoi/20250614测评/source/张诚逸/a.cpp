#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

char a[100006][10];
int n, maxn = 1, maxday[10];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 5; j++)
			cin >> a[i][j];
	int cur = 0;
	for(int j = 1; j <= 5; j++)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i][j] == 'Y') cnt++;
		}
		if(cnt > maxn)
		{
			maxn = cnt;
			memset(maxday, 0, sizeof maxday);
			cur = 0;
			maxday[++cur] = j;
		}
		else if(cnt == maxn) maxday[++cur] = j;
	}
	for(int i = 1; i <= cur; i++)
	{
		cout << maxday[i];
		if(i != cur) cout << ",";
		else cout << endl;
	}
	return 0;
}
