#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=100010;
bool vis[N];
int main()
{
	int g,p,cnt=0;
	cin>>g>>p;
	while(p--)
	{
		int a;
		cin>>a;
		bool flag=1;
		for(int i=a;i>=1;--i)
		{
			if(!vis[i])
			{
				vis[i]=1;
				flag=0;
				break;
			}
		}
		if(flag)
		{
			break;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
