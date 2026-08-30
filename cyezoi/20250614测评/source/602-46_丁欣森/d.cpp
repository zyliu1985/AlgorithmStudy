#include<bits/stdc++.h>
using namespace std;
int ancestor[100005],arr[100005];
int get_ancestor(int n)
{
	if(ancestor[n]==n)
		return n;
	return ancestor[n]=get_ancestor(ancestor[n]);
}
void union_set(int x,int y)
{
	x=get_ancestor(x);
	y=get_ancestor(y);
	if(x==y)
		return;
	ancestor[y]=x;
}
int main()
{
	int g,p;
	scanf("%d\n%d",&g,&p);
	for(int i=1;i<=g;i++)
		ancestor[i]=i;
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&arr[i]);	
		int t=get_ancestor(arr[i]);
		if(t==0)
		{
			printf("%d\n",i-1);
			return 0;
		}
		union_set(t-1,t);
	}
	printf("%d\n",p);
	return 0;
}
