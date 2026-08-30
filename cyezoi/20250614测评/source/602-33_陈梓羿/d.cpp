#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool pl[100005];
int b[100005];
int main()
{
	int n,m,ans,p;
	cin>>n>>m;
	if(m<=2000)
	{
		bool flag2=0;
		for(int i=1;i<=m;i++)
		{
			bool flag1=0;
			cin>>p;
			for(int j=p;j>=1;j--)
			{
				if(pl[j]==0)
				{
					pl[j]=1;
					flag1=1;
					break;
				}
			}
			if(flag1==0 && flag2==0)
			{
				ans=i-1;
				flag2=1;
			}
		}
		if(flag2==0) ans=m;
		cout<<ans;
	}
	return 0;
}
