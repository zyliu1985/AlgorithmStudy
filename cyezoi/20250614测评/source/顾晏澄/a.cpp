#include <bits/stdc++.h>
using namespace std;

char a[100000][5];
int ans[5];


int main()
{
	int n,mx = 0; 
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < 5;j++)
			cin >> a[i][j]; 
	}
	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(a[j][i] == 'Y')
				ans[i] ++;
		}
		mx = max(mx,ans[i]);
	}
	if(ans[0] == mx)
		cout << 1;
	if(ans[1] == mx) 
	{
		if(ans[0] == mx)
			cout << ",";
		cout << 2;
	}
	if(ans[2] == mx) 
	{
		if(ans[1] == mx || ans[0] == mx)
			cout << ",";
		cout << 3;
	}
	if(ans[3] == mx) 
	{
		if(ans[2] == mx || ans[1] == mx || ans[0] == mx)
			cout << ",";
		cout << 4;
	}
	if(ans[4] == mx) 
	{
		if(ans[3] == mx || ans[2] == mx || ans[1] == mx || ans[0] == mx)
			cout << ",";
		cout << 5;
	}
	return 0;
}
