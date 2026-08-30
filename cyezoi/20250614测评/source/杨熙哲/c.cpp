#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
int b[3][N];
int abs(int a,int b)
{
	if(a>=b)return a-b;
	else return b-a;
}
int main()
{
	int n;
	cin>>n;
	//cout<<n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<a[i]<<" ";
	}
	for(int i=1;i<=n;i++)
	{
		int minn=INT_MAX;
		for(int j=1;i+j-1<=n;j++)
		{			
			int cnt=0;
			int c=i;
			int d=j,e=i+j-1;
			while(c>0)
			{
				cnt+=abs(a[d],a[e]);
				c-=2;
				d++;
				e--;			
			}
			//cout<<cnt<<" ";
			minn=min(minn,cnt);
		}
		cout<<minn<<" ";
	}	
}
