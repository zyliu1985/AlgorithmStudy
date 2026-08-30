#include <bits/stdc++.h>
using namespace std;
long long n,m,a[3005],b[105],ans,cnt,ans2;
stack<int>Q;
stack<int>P;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;--i)
	{
		Q.push(a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+m);
	int k=1;
	if(m==1)
	{
		if(b[m]>a[1])P.push(b[m]);
		b[m]=0;
		k++;
	}
	P.push(a[1]);
	Q.pop();
	while(!Q.empty())
	{
		if(k==m+1)
		{
			while(!Q.empty())
			{
				P.push(Q.top());
				Q.pop();
			}
			break;
		}
		if(b[m]>Q.top())
		{
			P.push(b[k]);
			P.push(b[m]);
			b[k]=0;
			b[m]=0;
			k+=2;
			sort(b+1,b+1+m);
		}
		else
		{
			P.push(b[k]);
			b[k]=0;
			k++;
			P.push(Q.top());
			Q.pop();
		}
	}
	if(k!=m+1)
	{
		P.push(b[k]);
		P.push(b[m]);
		b[k]=0;
		b[m]=0;
		k+=2;
		sort(b+1,b+1+m);
	}
	while(!P.empty())
	{
		Q.push(P.top());
		P.pop();
	}
	while(!Q.empty())
	{
		cnt=1-cnt;
		if(cnt==1)ans+=Q.top();
		else ans2+=Q.top();
		Q.pop();
	}
	cout<<max(ans,ans2)<<endl;
	return 0;
}
