#include<bits/stdc++.h>
using namespace std;
int b[100100],m,s;
int main ()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=5;j++)
		{
			char c;
			cin>>c;
			if (c=='Y')
			b[j]++;
		}
	}
	for (int i=1;i<=5;i++)
	{
		m=max(m,b[i]);
	}
	for (int i=1;i<=5;i++)
	{
		if ((b[i]==m)&&(s==0))
		{
			cout<<i;
			s++;
		}
		else if (b[i]==m)
		{
			cout<<","<<i;
		}
	}
	return 0;
}
