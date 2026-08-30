#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5005;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int len=1;len<=n;len++)
	{
		ll minn=LONG_LONG_MAX;
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			ll sum=0;
			for(int i=0;i<=(r-l)/2;i++)
				sum+=abs(a[l+i]-a[r-i]);
			minn=min(minn,sum);
		}
		printf("%lld ",minn);
	}
	return 0;
}
