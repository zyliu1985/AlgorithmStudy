#include<bits/stdc++.h>
using namespace std;
int n,v[100010],vis[100010],a[100010];
int p(int i)
{
	return i&(i-1);
}
void add(int z)
{
	while(z<=n)
	{
		vis[z]++;
		z+=(z&(-z));
	}
}
int psq(int z)
{
	int sum=0;
	while(z)
	{
		sum+=vis[z];
		z=p(z);
	}
	return sum;
}
int main()
{
	int g;
	cin>>g>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(v[a[i]]==a[i])
		{
			cout<<i-1<<endl;
			return 0;
		}
		else if(psq(a[i])>=a[i])
		{
			cout<<i-1<<endl;
			return 0;
		}
		else
		{
			add(a[i]);
			v[a[i]]++;
		}
	}
	cout<<n<<endl;
	return 0;
}
