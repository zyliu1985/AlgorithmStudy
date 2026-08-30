#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int n;
int a[N];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n; i ++ )
	{
		int ans = 0x3f3f3f3f;
		for(int j = 1; j + i - 1 <= n; j ++ )
		{
			int cnt = 0;
			int l = j, r = j + i - 1;
			for(int k = l; k <= l + (r - l) / 2; k ++ ) cnt += abs(a[k] - a[r - k + l]);
//			cout << l << " " << r << " " << cnt << "\n";
ans = min(ans, cnt);
		}
//		cout << "\n\n";
		cout << ans << " ";
	}
}
