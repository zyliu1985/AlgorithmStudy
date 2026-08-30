#include<bits/stdc++.h>
using namespace std;

bool a[200010][3];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i][0];
	for(int i = 1;i <= n;i++)cin >> a[i][1];
	int ans = 0;
	for(int j = 0;j <= 1;j++)
		for(int i = 1;i <= n;i++)
			if(a[i][j])
			{
				ans += 3;
				if(a[i - 1][j])ans -= 2;
				if(i % 2 == 1 && a[i][j + 1])ans -= 2;
			}
	cout << ans;
	return 0;
}
