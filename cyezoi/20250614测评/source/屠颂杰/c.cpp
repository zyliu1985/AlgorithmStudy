#include <iostream>
#include <cmath>
using namespace std;

const int N=5005;

int n,a[N];

int f(int l,int len)
{
	int r=l+len,tot=0;
	
	for (int i=0;i<=(r-l)/2;i++) 
	{
		tot+=abs(a[l+i]-a[r-i]);
	}
	
	return tot;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	cin >> n;
	
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	for (int len=0;len<=n-1;len++)
	{
		int minn=1e9;
		
		for (int i=1;i<=n-len;i++)
		{
			minn=min(minn,f(i,len)); 
		}
		
		cout << minn << ' ';
	}
	return 0;
}

