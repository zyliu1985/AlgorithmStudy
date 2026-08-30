#include "bits/stdc++.h"
using namespace std ;
const int N = 3e3 + 10, M = 1e2 + 2 ;
int n, m, a[N], f[2][N], ans ;
int main()
{
//	freopen("E:/sample/e/data.in", "r", stdin) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 2 ; i <= n + 1 ; ++i) cin >> a[i] ;
	cin >> m ;
	if(m == 0)
	{
		for(int i = 2 ; i <= n ; ++i)
		{
			f[0][i] = max(f[0][i - 1], f[1][i - 1]) ;
			f[1][i] = f[0][i - 1] + a[i] ;
		}
		cout << max(f[0][n], f[1][n]) ;
		return 0 ;
	}
	if(m == 1)
	{
		cin >> m ;
		n++ ;
		a[1] = m ;
		for(int i = 2 ; i <= n ; ++i)
		{
			swap(a[i - 1], a[i]) ;
			memset(f, 0, sizeof(f)) ;
			for(int j = 1 ; j <= n ; ++j)
			{
				f[0][j] = max(f[0][j - 1], f[1][j - 1]) ;
				f[1][j] = f[0][j - 1] + a[j] ;
			}
			ans = max(ans, max(f[0][n], f[1][n])) ;
		}
		cout << ans ;
	}
	return 0 ;
}
