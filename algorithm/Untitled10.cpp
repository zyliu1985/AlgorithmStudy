#include <iostream>
#include <vector>
using namespace std;

int f[100005], d[100005];
string s;
vector<int> v[100005];
void dfs(int now){
	for (int i = 0; i < v[now].size(); i++)
		if (f[v[now][i]] == 0){
			f[v[now][i]] = now;
			d[v[now][i]] = d[now] + 1;
			dfs(v[now][i]);
		}
}
int find(int x, int y){
	bool fw = false, fm = false;
	if (x == y)
		if (s[x-1] == 'M') fm = true;
		else fw = true;
	while (x != y){
		if (s[x-1] == 'M') fm = true;
		else fw = true;
		if (s[y-1] == 'M') fm = true;
		else fw = true;
		if (d[x] > d[y]) x = f[x];
		else y = f[y];
		// cout << x << ' ' << y << endl;
	}
	if (fm && fw) return 2;
	else if (fm) return 1;
	else return 0;
}
int main(){
	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	f[1] = -1;
	d[1] = 1;
	dfs(1);
	// for (int i = 1; i <= n; i++) cout << d[i] << ' ';
	// cout << endl;
	string ans;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		char c;
		cin >> c;
		int x = find(a, b);
		// cout << x << endl;
		if (x == 2) ans += '1';
		else if (x == 1)
			if (c == 'M') ans += '1';
			else ans += '0';
		else 
			if (c == 'W') ans += '1';
			else ans += '0';
	}
	cout << ans << endl;
	return 0;
}