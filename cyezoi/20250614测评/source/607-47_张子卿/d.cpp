#include<bits/stdc++.h>
using namespace std;

int g,p;
int c[100010];

int lowbit(int x){return x & -x;}

void add(int x,int k)
{
	for(int i = x;i <= g;i += lowbit(i))
		c[i] += k;
}

int sum(int x)
{
	int res = 0;
	for(int i = x;i >= 1;i -= lowbit(i))
		res += c[i];
	return res;
}

int main()
{
	cin >> g >> p;
	for(int i = 1;i <= p;i++)
	{
		int a;
		cin >> a;
		if(sum(a) < a)add(a,1);
		else
		{
			cout << i - 1;
			break;
		}
	}
	return 0;
}
