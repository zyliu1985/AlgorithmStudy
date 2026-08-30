#include "bits/stdc++.h"
using namespace std ;
const int N = 2e5 + 5 ;
bool color[3][N] ;
int n, ans ;
int main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= 2 ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> color[i][j] ;
			if(!color[i][j]) continue ;
			ans += color[i][j] * 3 ;
			if(j % 2 != 0) ans -= color[i - 1][j] * 2 ;
			ans -= color[i][j - 1] * 2 ;
		}
	}
	cout << ans ;
	return 0 ;
}
/*
7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/
