#include <bits/stdc++.h>
using namespace std;
bool flag[100005];
int main()
{
	int g,n;
	cin>>g>>n;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		bool ok=false;
		for (int j=p;j>=1;j--)
		{
			if (!flag[j])
			{
				flag[j]=true;
				cnt++;
				ok=true;
				break;
			}
		}
		if (!ok)	break;
	}
	cout<<cnt<<endl;
}
