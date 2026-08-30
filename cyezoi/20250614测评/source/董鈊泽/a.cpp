#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=10;
int a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		for(int j=1;j<=5;++j)
		{
			char c;
			cin>>c;
			if(c=='Y')
			{
				a[j]++;
			}
		}
	}
	int maxx=0,idx=0;
	for(int i=1;i<=5;++i)
	{
		if(maxx<=a[i])
		{
			maxx=a[i];
			idx=i;
		}
	}
	for(int i=1;i<=5;++i)
	{
		if(a[i]==maxx)
		{
			cout<<i;
			if(i!=idx) cout<<",";
		}
	}
	return 0;
}
