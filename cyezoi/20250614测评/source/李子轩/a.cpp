#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			char q;
			cin >> q;
			if(q == 'Y')
			{
				a[j]++;
			}
		}
	}
	int maxx = 0;
	for(int i = 1; i <= 5; i++)
	{
		if(a[i] >= maxx)
		{
			maxx = a[i];
		}
	}
	int s = 0;
	for(int i = 1; i <= 5; i++)
	{
		if(a[i] == maxx)
		{
			s++;
		}
	}
	int w = 0;
	for(int i = 1; i <= 5; i++)
	{
		if(a[i] == maxx)
		{
			cout << i;
			if(w != s - 1)
			{
				cout << ",";
			}
			w++;
		}
	}
	return 0;
}
