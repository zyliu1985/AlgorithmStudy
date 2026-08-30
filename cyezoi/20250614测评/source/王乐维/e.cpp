#include <bits/stdc++.h>
using namespace std;

long long k, n, m, A, B;
long long minn = LONG_LONG_MAX;

struct node
{
	long long a, b, t, h;
}x[1010];

vector<node> g[1010];
queue<node> q;
long long used[1010];
int main(void)
{
	//freopen("e.in", "r", stdin);
	//freopen("e.out", "w", stdout);
	
	cin >> k >> n >> m;
	
	for(long long i = 1;i <= m;i ++)
	{
		cin >> x[i].a >> x[i].b >> x[i].t >> x[i].h;
		g[x[i].a].push_back((node){x[i].a, x[i].b, x[i].t, x[i].h});
		g[x[i].b].push_back((node){x[i].b, x[i].a, x[i].t, x[i].h});
	}
	cin >> A >> B;
	//bfs
	for(long long i = 0;i < g[A].size();i ++)
		q.push((node){A, g[A][i].b, g[A][i].t, g[A][i].h});
	used[A] = 1;
	while(!q.empty())
	{
		long long aa = q.front().a, bb = q.front().b, tt = q.front().t, hh = q.front().h;
		used[aa] = 1;
		q.pop();
		for(long long i = 0;i < g[bb].size();i ++)
			if(used[g[bb][i].b] == 0)
				q.push((node){bb, g[bb][i].b, tt + g[bb][i].t, hh + g[bb][i].h});
						
		if(bb == B && hh < k)
			minn = min(minn, tt);
					
	}
	if(minn != LONG_LONG_MAX)
		cout << minn << endl;
	else
		cout << -1 << endl;
	
	return 0;
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
