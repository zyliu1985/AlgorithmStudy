#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct sj
{
	int time;
	int wz;
};
queue<sj>q;
int jl[3002][3002];
int ms[3002][3002];
vector<int> lt[3002];
int a[3002];
int b[3002];
int t[3002];
int h[3002];
bool mem[3002];
int main()
{
	int k,n,m,qd,zd,min = 30000020;
	cin >> k >> n >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> a[i] >> b[i] >> t[i] >> h[i];
		jl[a[i]][b[i]] = t[i];
		jl[b[i]][a[i]] = t[i];
		ms[a[i]][b[i]] = h[i];
		ms[b[i]][a[i]] = h[i];
		lt[a[i]].push_back(b[i]);
		lt[b[i]].push_back(a[i]);
	}
	cin >> qd >> zd;
	sj tmp;
	tmp.time = 0;
	tmp.wz = qd;
	q.push(tmp);
	while (!q.empty())
	{
		tmp = q.front();
		sj tmp2 = tmp;
		q.pop();
		if (mem[tmp.wz]) continue;
		mem[tmp.wz] = 1;
		if (tmp.wz == zd)
		{
			if (tmp.time < min) min = tmp.time;
			continue;
		}
		for (int i = 0;i < lt[i].size();i++)
		{
			int f = lt[tmp.wz][i];
			if (ms[tmp.wz][f]) continue;
			tmp2.time += jl[tmp.wz][f];
			tmp2.wz = f;
			q.push(tmp2);
		}
	}
	if (mem[zd]) cout << min;
	else cout << -1;
	return 0;
}
