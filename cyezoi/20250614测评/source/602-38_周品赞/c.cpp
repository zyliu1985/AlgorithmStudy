#include "bits/stdc++.h"
using namespace std ;
const int N = 5e3 + 3 ;
int n, a[N], f[N][N] ;
//f[i][j]:长度为i,以j为起点的区间的非对称值 
int main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
	cout << 0 << ' ' ;
	for(int i = 2 ; i <= n ; ++i)
	{
		int minN = 5e8 + 8 ;
		for(int j = 1 ; j <= n - i + 1 ; ++j)
		{
			int tmp = abs(a[j] - a[j + i - 1]) ;
			f[i][j] = f[i - 2][j + 1] + tmp ;
			minN = min(minN, f[i][j]) ;
		}
		cout << minN << ' ' ;
	}
	return 0 ;
}
