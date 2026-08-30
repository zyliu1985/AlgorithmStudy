#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int c[5005][5005];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = i-1; j >= 1; j--)c[j][i]=abs(a[i]-a[j])+c[j+1][i-1];
	}
	for(int i = 1; i <= n; i++)
	{
		int minn=1e9;
		for(int j = 1; i+j-1<=n; j++)
		{
			minn=min(minn,c[j][i+j-1]);
			if(minn==0)break;
		}
		cout << minn;
		if(i<n)cout << " ";
	}
}
