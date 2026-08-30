#include<bits/stdc++.h>
using namespace std;
int G,P,g[100019],cnt;
bool a[100019];
int main()
{
	cin>>G;
	cin>>P;
	for(int i=1;i<=P;i++)
	{
		cin>>g[i];
	}
	for(int i=1;i<=P;i++)
	{
		bool f=0;
		for(int j=g[i];j>0;j--)
		{
			if(a[j]==0)
			{
				a[j]=1;
				f=1;
				cnt++;
				break;
			}
		}
		if(f==0)
		{
			cout<<cnt<<endl;
			return 0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
