#include <iostream>
#include <cstring>
using namespace std;

const int N=3e3+5;

int n,m,a[N],b,t[N],dp[N]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i=1;i<=n;i++) cin >> a[i];
	
	cin >> m;
	
	if (m==0)
	{
		dp[1]=a[1];
		
		for (int i=3;i<=n;i++)
		{
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		}
		
		cout << dp[n];
		return 0;
	}
	else if (m==1)
	{
		cin >> b;
		int maxn=-1e9;
		
		for (int i=1;i<=n;i++)
		{
			memset(t,0,sizeof t);
			memset(dp,-0x3f,sizeof dp);
			
			for (int j=1;j<=i-1;j++) t[j]=a[j];
			
			t[i]=b;
			
			for (int j=i;j<=n;j++) t[j+1]=a[j];
		
			dp[1]=a[1];
			
			for (int j=2;j<=n+1;j++)
			{
				dp[j]=max(dp[j-2]+t[j],dp[j-1]);
			}
			
			maxn=max(maxn,dp[n+1]);
		}
		
		cout << maxn;
	}
	
	return 0;
}

// ╤тед 
/*
100+200+100+200+50+180=830
*/
