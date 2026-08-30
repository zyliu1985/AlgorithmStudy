#include<bits/stdc++.h>
using namespace std;
int n,a[10],maxn=0;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char c;
		for(int j = 1; j <= 5; j++)
		{
			cin >> c;
			if(c=='Y')a[j]++;
		}
	}
	for(int i = 1; i <= 5; i++)maxn=max(maxn,a[i]);
	bool flag=false;
	for(int i = 1; i <= 5; i++)
	{
		if(a[i]==maxn)
		{
			if(flag)cout << ",";
			flag=true;
			cout << i;
		}
	}
}
