#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
bool flag[100005];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		while(flag[a]&&a!=0)
		{
			a--;
		}
		if(a!=0)flag[a]=1;
		else 
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
}
/*
4
3
4
1
1

4
6
2
2
3
3
4
4
*/
