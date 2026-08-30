#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=200010;
int a[N],b[N];
int main()
{
	int c,sum=0;
	cin>>c;
	for(int i=1;i<=c;++i)
	{
		cin>>a[i];
		if(a[i]==1) sum+=3;
	}
	for(int i=1;i<=c;++i)
	{
		cin>>b[i];
		if(b[i]==1) sum+=3;
	}
	for(int i=1;i<=c;++i)
	{
		if(a[i]==a[i+1]&&a[i]==1) sum-=2;
		if(b[i]==1&&b[i+1]==1) sum-=2;
		if(i%2==1&&a[i]==1&&b[i]==1) sum-=2;
	}
	cout<<sum<<endl;
	return 0;
}
