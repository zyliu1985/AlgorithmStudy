#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct half{
	__int128 p, q;
} dis[100005];
int n, m;
int rd[100005];
int coff;
bool from[100005];
vector<int> v[100005];
queue<int> q;
__int128 gcd(long long x, long long y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
half add(half x, half y){
	__int128 nq = x.q / gcd(x.q, y.q) * y.q;
	__int128 np = x.p * (nq / x.q) + y.p * (nq / y.q);
	__int128 yue = gcd(np, nq);
	return half{np / yue, nq / yue};
}
void tbpx(){
	for (int i = 1; i <= n; i++)
		if (rd[i] == 0){
			dis[i] = half{1, 1};
			coff++;
			from[i] = true;
			q.push(i);
		}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++){
			rd[v[x][i]]--;
			__int128 yue = gcd(dis[x].p, dis[x].q * v[x].size());
			dis[v[x][i]] = add(dis[v[x][i]], half{dis[x].p / yue, dis[x].q * v[x].size() / yue});
			if (rd[v[x][i]] == 0)
				q.push(v[x][i]);
		}
	}
}
int main(){
	freopen("data1.in", "r", stdin);
	freopen("data1.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		rd[y]++;
	}
	for (int i = 1; i <= n; i++)
		dis[i].q = 1;
	tbpx();
	for (int i = 1; i <= n; i++)
		if (dis[i].p == coff && dis[i].q == 1 && !from[i])
			cout << i << '\n';
	return 0;
}