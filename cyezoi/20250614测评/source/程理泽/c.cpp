#include<iostream>
using namespace std;

int a[5002][5002];
int min[5002];
int t[5002];
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> t[i];
		a[2][i-1] = abs(t[i-1]-t[i]);
	}
	for (int i = 1;i <= n;i++)
	{
		cout << min[i];
		min[i+1] = 
	}
}
