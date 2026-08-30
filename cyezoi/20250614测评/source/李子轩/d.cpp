#include<bits/stdc++.h>
using namespace std;
bool a[100003];
int main()
{
	int n, p;
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
	{
		a[i] = 1;
	}
	int sum = 0;
	for(int i = 1; i <= p; i++)
	{
		int q;
		cin >> q;
		for(int j = q; j >= 1; j--)
		{
			if(j == 1 && !a[j])
			{
				cout << sum;
				return 0;
			}
			if(a[j]) 
			{
				a[j] = 0;
				sum++;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}
