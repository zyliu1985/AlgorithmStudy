// ‰»Î”–ø’∏Ò 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int c,up[MAXN],down[MAXN];
int cnt=0,ans=0;
int main()
{
	cin>>c;
	for(int i=1;i<=c;i++)
	{
		cin>>up[i];
		if(up[i]==1) cnt++;
	}
	for(int i=1;i<=c;i++)
	{
		cin>>down[i];
		if(down[i]==1) cnt++;
	}
	ans=cnt*3;
	for(int i=1;i<c;i++)
	{
		if(up[i]==1 && up[i+1]==1) ans-=2;
	}
	for(int i=1;i<c;i++)
	{
		if(down[i]==1 && down[i+1]==1) ans-=2;
	}
	for(int i=1;i<=c;i+=2)
	{
		if(up[i]==1 && down[i]==1) ans-=2;
	}
	cout<<ans;
	return 0;
}
