#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int p[300005], c[300005];
int ch[600005], nxtb[600005], top[300005];
long long val[600005]; 
vector<int> v[300005];
int merge(int x, int y){
	if (x == 0) return y;
	if (y == 0) return x;
	if (val[x] < val[y]) swap(x, y); 
	nxtb[y] = ch[x];
	ch[x] = y;
	return x;
}
int merges(int x){
	if (!nxtb[x]) return x;
	int y = nxtb[x];
	int z = nxtb[y];
	nxtb[x] = 0, nxtb[y] = 0;
	return merge(merge(x, y), merges(z));
}
int del(int x){
	if (!ch[x]) return -1;
	int newtop = merges(ch[x]);
	ch[x] = 0;
	return newtop;
}
//void print(int x){
//	cout << val[x] << ' ';
//	if (ch[x]) print(ch[x]);
//	if (nxtb[x]) print(nxtb[x]);
//}
void dfs(int x){
//	cout << "x: " << x << '\n'; 
	if (x > n){
		int a = (x - n) * 2 - 1;
		int b = (x - n) * 2;
		val[a] = val[b] = 0;
		top[x] = merge(a, b);
//		cout << "create " << x << '\n';
		return; 
	}
	for (int i = 0; i < v[x].size(); i++){
		dfs(v[x][i]);
		int a = top[v[x][i]];
		top[v[x][i]] = del(top[v[x][i]]);
		int b = top[v[x][i]]; 
		val[a] += c[v[x][i]], val[b] += c[v[x][i]];
//		cout << "deal: " << a << ',' << b << ": " << val[a]-c[v[x][i]] << ',' << val[b]-c[v[x][i]] << "->" << val[a] << ',' << val[b] << '\n';
		top[v[x][i]] = merge(b, a);
		if (!top[x]) top[x] = top[v[x][i]];
		else top[x] = merge(top[x], top[v[x][i]]);
	}
	for (int i = 0; i < v[x].size() - 1; i++)
		top[x] = del(top[x]);
//	cout << x << ": ";
//	print(top[x]);
//	cout << '\n';
//	cout << "return: " << x << '\n'; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long ans = 0; 
	cin >> n >> m;
	for (int i = 2; i <= n; i++){
		cin >> p[i] >> c[i];
		v[p[i]].push_back(i);
		ans += c[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> p[i + n] >> c[i + n];
		v[p[i + n]].push_back(i + n);
		ans += c[i + n]; 
	}
	dfs(1); 
	top[1] = del(top[1]);
	do {
//		cout << val[top[1]] << ',';
//		print(top[1]);
//		cout << '\n';
		ans -= val[top[1]];
		top[1] = del(top[1]);
	} while (top[1] != -1);
//	cout << '\n';
	cout << ans << '\n';
	return 0;
}

