#include<cstdio>
using namespace std;
typedef long long ll;
const int f[][2]={{0,1},{1,0}}; 
const int N=2e5+5;
int n;
int mp[5][N];
ll ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mp[i][j]);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]==1)
				cnt1++;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<2;k++)
			{
				int nx=i+f[i][0],ny=j+f[i][1];
				if(nx>2||ny>n)continue;
				if(mp[nx][ny]==1)
					cnt2++;
			}
	ans=cnt1*3-cnt2;
	printf("%lld\n",ans);
	return 0;
}
