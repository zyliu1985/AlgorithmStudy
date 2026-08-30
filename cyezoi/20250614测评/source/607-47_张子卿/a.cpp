#include<bits/stdc++.h>
using namespace std;

int cnt[10];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= 5;j++)
		{
			char a;
			cin >> a;
			if(a == 'Y')cnt[j]++;
		}
	int maxn = 0,sum= 0;
	for(int i = 1;i <= 5;i++)
		maxn = max(maxn,cnt[i]);
	for(int i = 1;i <= 5;i++)
		if(cnt[i] == maxn)sum++;
	for(int i = 1;i <= 5;i++)
		if(cnt[i] == maxn)
		{
			sum--;
			cout << i;
			if(sum != 0)cout << ",";
		}
	return 0;
}
