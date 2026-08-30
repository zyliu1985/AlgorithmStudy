#include<bits/stdc++.h>
using namespace std;
int a[100010],f=0,b[100100];
bool t;
int main ()
{
	int g,p;
	cin>>g>>p;
	for (int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=p;i++)
	{
        t=false;
		if (a[i]>p)
		{
			a[i]+=p-a[i];
		}
		for (int j=a[i];j>0;j--)
		{
			if (b[j]==0)
			{
				f++;
				b[j]+=1;
				t=true;
				break;
			}
		}
		if (t)
		{
			cout<<f;
			break;
		}
	}
	cout<<f;
	return 0;
}
