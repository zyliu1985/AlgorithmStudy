#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct node
{
	int cnt,id;
};

bool cmp(node x,node y)
{
	return x.cnt>y.cnt;	
}

node a[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=5;j++)
		{
			char c;
			cin >> c;
			
			if (c=='Y') a[j].cnt++;
			
			a[j].id=j;
		}
	}
	
	sort(a+1,a+6,cmp);
	
	for (int i=1;i<=5;i++)
	{
		cout << a[i].id;
		
		if (a[i].cnt!=a[i+1].cnt)
		{
			break;
		}
		
		cout << ',';
	}
	return 0;
}
