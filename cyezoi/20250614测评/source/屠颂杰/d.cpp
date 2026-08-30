#include <iostream>
using namespace std;

const int N=1e5+5;

int a[N];
bool vis[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int g,p;
	cin >> g >> p;
	
	for (int i=1;i<=p;i++)
	{
		cin >> a[i];
	}
	
	for (int i=1;i<=p;i++)
	{
		bool flag=1;
		
		for (int j=a[i];j>=1;j--)
		{
			if (!vis[j])
			{
				vis[j]=1;
				flag=0;
				break;
			}
		}
		
		if (flag) 
		{
			cout << i-1 << ' ';
			return 0;
		}
	}
	
	cout << p;
	return 0; 
}
