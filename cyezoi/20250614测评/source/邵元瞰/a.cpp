#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val,id;
} cnt[10];
bool cmp(node x,node y)
{
	if (x.val!=y.val)	return x.val>y.val;
}
queue<int> q;
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=5;i++)
	{
		cnt[i].id=i;
	}
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for (int j=0;j<s.size();j++)
		{
			if (j=='Y')	cnt[j+1].val++;
		}
	}
	sort(cnt+1,cnt+6,cmp);
	for (int i=1;i<=5;i++)
	{
		if (cnt[i].val==cnt[1].val)	q.push(cnt[i].id);
	}
	while (!q.empty())
	{
		if (q.size()==1)
		{
			cout<<q.front()<<endl;
		}
		else
		{
			cout<<q.front()<<",";
		}
	}
}
