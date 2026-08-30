#include <bits/stdc++.h>
using namespace std;
int k, n, m;
struct x{
	int t;
	int h;
	int e;
};
int a, b;
vector <x> v[2025];
int d[2025][2];
int f[2024];
int main(){
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		x u;
		u.t = t;
		u.h = h;
		u.e = b;
		v[a].push_back(u);
		u.e = a;
		v[b].push_back(u);
	}
	cin >> a >> b;
	for (int i = 1; i <= n; i++){
		d[i][0] = INT_MAX;
	}
	f[a] = 1;
	d[a][0] = 0;
	while (f[b] == 0 || f[b] == 1){
		for (int i = 1; i <= n; i++){
			if (f[i] == 1){
				f[i] = 2;
				for (int j = 0; j < v[i].size(); j++){
					if (d[i][0] + v[i][j].t < d[v[i][j].e][0] && d[i][1] + v[i][j].h < k){
						d[v[i][j].e][0] = d[i][0] + v[i][j].t;
						f[v[i][j].e] = 1;
						d[v[i][j].e][1] = d[i][1] + v[i][j].h;
					}
				}
			}
		}
	}
	cout << d[b][0];
	return 0;
}
