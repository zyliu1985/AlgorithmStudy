#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[3010];
long long b[110];
long long f[3010][5][210];
int main( ){
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(long long i=1;i<=m;i++)
		cin>>b[i];
	int sum=0;
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			f[i][0][j]=max(f[i-1][0][j],f[i-1][1][j]);
			f[i][1][j]=f[i-1][0][j]+a[i];
			f[i][0][100+j]=max(f[i-1][0][j]+b[j],max(f[i-1][0][100+j],f[i-1][1][100+j]));
			f[i][1][100+j]=max(max(f[i-1][0][j],f[i-1][1][j])+a[i],f[i-1][0][100+j]+a[i]);
		}
		
		f[i][0][201]=max(f[i-1][0][201],f[i-1][1][201]);
		f[i][1][201]=f[i-1][0][201]+a[i];
		
		
	}
	long long maxn=0;
	for(int i=1;i<=201;i++)
		maxn=max(maxn,max(f[n][0][i],f[n][1][i]));
	cout<<maxn;
	return 0;
}
