#include<bits/stdc++.h>
using namespace std;
int g,p;
int a[100005];
int main()
{
	cin >> g >> p;
	for(int i = 1; i <= p; i++)cin >> a[i];
	int l=1,r=p,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		sort(a+1,a+mid+1);
		bool f=true;
		for(int i = 1; i <= mid; i++)if(a[i]<i){f=false;break;}
		if(f)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans;
}
