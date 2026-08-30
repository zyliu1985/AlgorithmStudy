#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> v[100005];
int c[100005], sz[100005], now;
bool vis[100005], cnt[100005];
long long ans[100005], add[100005], cd[100005], nowcd[100005], nowadd, lstadd, bonus, lstsz;
stack<int> st, st2;
void calcsz(int x, int fa){
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]){
			calcsz(v[x][i], x);
			sz[x] += sz[v[x][i]];
		}
}
int calcrt(int x, int fa, int rt){
	if (sz[rt] - sz[x] > sz[rt] / 2) return -1;
	bool flag = true;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]){
			if (sz[v[x][i]] > sz[rt] / 2){
				flag = false;
				break;
			}
		}
	if (flag) return x;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]){
			int re = calcrt(v[x][i], x, rt);
			if (re != -1) return re;
		}
	return -1;
}
void calcadd(int x, int fa, int rt){
	bool first = 0;
	if (!cnt[c[x]]){
		cnt[c[x]] = true;
		if (!cd[c[x]]) st.push(c[x]);
		cd[c[x]] += sz[x];
		nowadd++;
		first = true;
	}
	lstadd += nowadd;
	add[rt] += nowadd;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]])
			calcadd(v[x][i], x, rt);
	if (first){
		cnt[c[x]] = false;
		nowadd--;
	}
}
void calcans(int x, int fa, int rt){
	bool first = 0;
	if (!cnt[c[x]]){
		cnt[c[x]] = true;
		nowadd++;
		bonus += cd[c[x]] - nowcd[c[x]];
		first = true;
	}
	ans[x] += nowadd * lstsz + (lstadd - add[rt]) - bonus + nowadd;
	ans[now] += nowadd;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]])
			calcans(v[x][i], x, rt);
	if (first){
		cnt[c[x]] = false;
		nowadd--;
		bonus -= cd[c[x]] - nowcd[c[x]];
	}
}
void calcnowcd(int x, int fa){
	bool first = 0;
	if (!cnt[c[x]]){
		cnt[c[x]] = true;
		if (!nowcd[c[x]]) st2.push(c[x]);
		nowcd[c[x]] += sz[x];
		first = true;
	}
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]])
			calcnowcd(v[x][i], x);
	if (first){
		cnt[c[x]] = false;
	}
}
void solve(int x){
	calcsz(x, 0);
	int rt = calcrt(x, 0, x);
	calcsz(rt, 0);
	now = rt;
	ans[rt]++;
	nowadd = 1;
	cnt[c[rt]] = true;
	lstadd = 0;
	for (int i = 0; i < v[rt].size(); i++)
		if (!vis[v[rt][i]])
			calcadd(v[rt][i], rt, v[rt][i]);
	for (int i = 0; i < v[rt].size(); i++)
		if (!vis[v[rt][i]]){
			calcnowcd(v[rt][i], rt);
			lstsz = sz[rt] - sz[v[rt][i]] - 1;
			bonus = lstsz;
			calcans(v[rt][i], rt, v[rt][i]);
			add[v[rt][i]] = 0;
			while (!st2.empty()) nowcd[st2.top()] = 0, st2.pop();
		}
	while(!st.empty()) cd[st.top()] = 0, st.pop();
	cnt[c[rt]] = false;
	vis[rt] = true;
	for (int i = 0; i < v[rt].size(); i++)
		if (!vis[v[rt][i]]) solve(v[rt][i]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}

