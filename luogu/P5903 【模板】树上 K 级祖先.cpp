#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

unsigned int s;
unsigned int get(unsigned int x){
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x;
}
int rt;
int n, q;
int f[500005][20], tp[500005], sz[500005];
int mem[1000005], head[500005], cur = 0;
int Log2[500005];
vector<int> v[500005];
int d[500005], maxd[500005], hvch[500005];
void init(int x){
	maxd[x] = d[x];
	for (int i = 0; i < v[x].size(); i++){
		d[v[x][i]] = d[x] + 1;
		init(v[x][i]);
		maxd[x] = max(maxd[x], maxd[v[x][i]]); 
		if (maxd[v[x][i]] > maxd[hvch[x]]){
			hvch[x] = v[x][i];
		}
	}
}
void hvinit(int x, int top){
	tp[x] = top;
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == hvch[x]){
			hvinit(v[x][i], top);	
			sz[x] += sz[v[x][i]];
		} else {
			hvinit(v[x][i], v[x][i]);
		}
	}
	if (x == top){
		head[x] = cur;
		// 先下后上 
		int now = x;
		for (int i = 0; i < sz[x]; i++){
			mem[cur + i] = now;
			now = hvch[now];
		}
		now = x;
		for (int i = sz[x]; i < 2*sz[x]; i++){
			mem[cur + i] = now;
			now = f[now][0];
		}
		cur += 2 * sz[x];
//		if (cur > 1e6){
//			cout << "------";
//			exit(0);
//		}
	}
}
void bitinit(){
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i-1]][i-1];
	Log2[0] = -1;
	for (int i = 1; i <= n; i++)
		Log2[i] = Log2[i / 2] + 1;
}
int solve(int x, int k){
	if (k == 0) return x;
	x = f[x][Log2[k]];
	k -= (1 << Log2[k]);
	k -= sz[tp[x]] - sz[x];
	if (k <= 0){
		return mem[head[tp[x]] - k];
	} else {
		return mem[head[tp[x]] + sz[x] + k];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	for (int i = 1; i <= n; i++){
		cin >> f[i][0];
		if (f[i][0] == 0) rt = i;
		else v[f[i][0]].push_back(i);
	}
	d[rt] = 1;
	init(rt);
	hvinit(rt, rt);
	bitinit();
	long long fin_ans = 0, lst_ans = 0; 
	for (int i = 1; i <= q; i++){
		auto x = (get(s) ^ lst_ans) % n + 1;
		auto k = (get(s) ^ lst_ans) % d[x];
		cout << x << ' ' << k << '\n';
		lst_ans = solve(x, k);
		if (lst_ans == 0){
			cout << "WRONG!";
			return 0;
		}
		fin_ans ^= lst_ans * i;
	}
	cout << fin_ans << '\n';
	return 0;
}

