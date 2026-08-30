#include "bits/stdc++.h"
using namespace std ;
const int K = 202, N = 2e3 + 3, M = 1e4 + 4 ;
struct Node {int x, y, z ;};
int m, n, k, f[K][N], a, b, ans = 1e9 + 9 ;
//f[i][j]:消耗了 i cm,到达 j 岛屿时的最短时间 
vector<Node> g[N] ;
inline void init()
{
	memset(f, 0x3f, sizeof(f)) ;
	f[0][a] = 0 ;
}
int main()
{
//	freopen("E:/sample/e/data.in", "r", stdin) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> k >> n >> m ;
	for(int i = 1 ; i <= m ; ++i)
	{
		int u, v, t, h ;
		cin >> u >> v >> t >> h ;
		g[u].push_back((Node){v, t, h}) ;
		g[v].push_back((Node){u, t, h}) ;
	}
	cin >> a >> b ;
	init() ;
	for(int i = 0 ; i < k ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			for(int k = 0 ; k < g[j].size() ; ++k)
			{
				int u = g[j][k].x, t = g[j][k].y, h = g[j][k].z ;
				if(h > i) continue ;
				f[i][j] = min(f[i][j], f[i - h][u] + t) ;
			}
		}
	}
	for(int i = 0 ; i < k ; ++i) ans = min(ans, f[i][b]) ;
	cout << ans << endl ;
	return 0 ;
}
/*
10 4 7 
1 2 4 4 
1 3 7 2 
3 1 8 1 
3 2 2 2 
4 2 1 6 
3 4 1 1 
1 4 6 12 
1 4
*/
/*
大爱ftx
  .#%\ /%#.
 /####V####\
 (#########)
  \#######/
    \###/
      V
求保佑 T1 T2 T3 T4 T5 all AC
JTO OTZ 
*/
