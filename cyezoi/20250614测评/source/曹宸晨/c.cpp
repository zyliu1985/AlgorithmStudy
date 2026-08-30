#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 2;
int n,a[N],box[N];
signed main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for(int i = 1; i <= n; i++) box[i] = 2e9;
	for(int i = 1; i <= n; i++)
	{
		int l = i,r = i,ans = 0;
		while(l >= 1 && r <= n)
		{
			ans += abs(a[l] - a[r]);
			box[r - l + 1] = min(box[r - l + 1],ans);
			l--,r++;
		}
	}
	for(int i = 1; i < n; i++)
	{
		int l = i,r = i + 1,ans = 0;
		while(l >= 1 && r <= n)
		{
			ans += abs(a[l] - a[r]);
			box[r - l + 1] = min(box[r - l + 1],ans);
			l--,r++;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ",box[i]);
}
