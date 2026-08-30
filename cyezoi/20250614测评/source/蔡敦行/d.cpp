#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
bool flag[N];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>=1;j--)
			if(!flag[j])
			{
				flag[j]=true;
				goto EXIT;
			}
		printf("%d\n",i-1);
		return 0;
		EXIT:;
	}
	return 0;
}
