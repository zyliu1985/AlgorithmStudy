#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int b[N];
int main()
{
	int g;
	int p;
	cin>>g>>p;
	int sum=0;
	for(int i=1;i<=p;i++)cin>>a[i];
	for(int i=1;i<=p;i++)
	{
		if(b[a[i]]==0)
		{
			b[a[i]]++;
			sum++;
		}
		else if(b[a[i]]!=0)
		{
			int cnt=0;
			for(int j=a[i];j>=1;j--)
			{
				if(b[j]==0)
				{
					b[j]++;
					sum++;
					cnt++;
					break;
				}
			}
			if(cnt==0)
			{
				cout<<sum;
				break;
			}
		}
	}
}
