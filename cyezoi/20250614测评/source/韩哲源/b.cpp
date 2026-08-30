#include<bits/stdc++.h>
using namespace std;
int c,cnt;
bool a[3][200019];
int main()
{
	cin>>c;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) cnt+=3;
		}
	}
	for(int i=1;i<c;i++)
	{
		if(a[1][i]==1)
		{
			if(a[1][i+1]==1) cnt-=2;
			if(a[2][i]==1) cnt-=2;
		}
	}
	for(int i=1;i<c;i++)
	{
		if(a[2][i]==1)
		{
			if(a[2][i+1]==1) cnt-=2;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
