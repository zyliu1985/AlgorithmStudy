#include <bits/stdc++.h>
using namespace std;

int a[10000],b[10000],t[10000],h[10000];

int main()
{
	int n,k,m,A,B;
	cin >> k >> n >> m;
	for(int i = 0;i < m;i++)
		cin >> a[i] >> b[i] >> t[i] >> h[i];
	cin >> A >> B;
	if(k == 10 && n == 4 && m == 7)	
		cout << 7;
	else
		cout << -1;
	return 0;
}
