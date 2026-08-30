#include "bits/stdc++.h"
using namespace std ;
const int N = 1e5 + 3 ;
int g, p, a[N], f[N], l[N], r[N], book[N], ans ;
inline void init()
{
	for(int i = 1 ; i <= g ; ++i)
		f[i] = l[i] = r[i] = i ;
}
int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]) ;
}
void connect(int x, int y)
{
	if(x == y) return ;
	int tx = find(x), ty = find(y) ;
	if(tx > ty) swap(tx, ty) ;
	if(r[tx] + 1 != l[ty]) return ;
	if(!book[ty]) return ;
	f[ty] = tx ;
	r[tx] = r[ty] ;
}
int main()
{
//	freopen("E:/sample/d/data.in", "r", stdin) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> g >> p ;
	init() ;
	for(int i = 1 ; i <= p ; ++i)
	{
		cin >> a[i] ;
		int tmp = find(a[i]) ;
		if(tmp == 1 && book[1]) break ;
		if(book[tmp]) book[tmp - 1] = 1, connect(tmp - 1, tmp) ;
		else book[tmp] = 1, connect(max(1, tmp - 1), tmp), connect(tmp, tmp + 1) ;
		ans++ ;
	}
	cout << ans ;
	return 0 ;
}
