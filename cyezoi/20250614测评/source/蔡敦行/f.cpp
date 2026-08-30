#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3005,M=105;
int n,m;
int a[N],b[M],tmp[2*N];
int dp[2*N],ans;
bool vis[2*N];
int cal()
{
	vector<int>array;
	array.push_back(0);
	for(int i=0;i<=2*n;i++)
		if(tmp[i])
			array.push_back(tmp[i]);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<(int)array.size();i++)
	{
		dp[i]=dp[i-1];
		if(i>=2)
			dp[i]=max(dp[i],dp[i-2]+array[i]);
	}
	return dp[array.size()-1];
}
void dfs(int step)
{
	if(step==m+1)
	{
		int sum=cal();
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=2*n;i+=2)
		if(!vis[i])
		{
			tmp[i]=b[step];
			vis[i]=true;
			dfs(step+1);
			tmp[i]=0;
			vis[i]=false;
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tmp[2*i-1]=a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	dfs(1);
	printf("%d\n",ans);	
	return 0;
}
