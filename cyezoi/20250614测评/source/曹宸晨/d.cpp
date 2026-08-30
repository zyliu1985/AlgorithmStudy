#include <bits/stdc++.h>
using namespace std;
int n,m;
set <int> st;
signed main()
{
	scanf("%d%d",&m,&n);
	for(int i = 1; i <= m; i++) st.insert(i);
	for(int i = 1,a; i <= n; i++)
	{
		scanf("%d",&a);
		set<int>::iterator it = st.upper_bound(a);
		if(it == st.begin())
		{
			printf("%d",i - 1);
			return 0;
		}
		it--;
		st.erase((*it));
	}
	printf("%d",n);
}
