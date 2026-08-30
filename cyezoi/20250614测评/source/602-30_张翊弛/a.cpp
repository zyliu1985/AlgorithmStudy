#include <bits/stdc++.h>
using namespace std;
int n;
struct Node
{
	int x, id;
} cnt[5];
string s;
bool cmp(Node a, Node b)
{
	if (a.x == b.x)
		return a.id < b.id;
	return a.x > b.x;
}
signed main()
{
	cin >> n;
	for (int i = 0; i < 5; i++)
		cnt[i].id = i + 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 0; j < 5; j ++)
			if (s[j] == 'Y')
				cnt[j].x++;
	}
	sort(cnt, cnt + 5, cmp);
	int maxx = cnt[0].x;
	cout << cnt[0].id;
	for (int i = 1; i < 5; i++)
	{
		if (cnt[i].x != maxx)
			break;
		cout << "," << cnt[i].id;
	}
}
