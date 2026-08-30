#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[500005];
vector<double> p[500005];
vector<double> apls[500005];
double dirp[500005], ansp[500005];
void up(int x, int fa){
	if (v[x].size() == 1 && x != 1){
		ansp[x] = dirp[x];
		apls[x].push_back(0);
		return;
	}
	double fail = dirp[x];
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa){
			apls[x].push_back(0);
			continue;
		}
		up(v[x][i], x);
		apls[x].push_back(fail);
		fail *= 1 - (1 - ansp[v[x][i]]) * (1 - p[x][i]);
	}
	ansp[x] = fail;
	fail = 1;
	for (int i = v[x].size()-1; i >= 0; i--){
		if (v[x][i] == fa)
			continue;
		apls[x][i] *= fail;
//		cout << x << ": " << apls[x].size() << ',' << apls[x][i] << '\n';
		fail *= 1 - (1 - ansp[v[x][i]]) * (1 - p[x][i]);
	}
//	if (apls[x].size() != v[x].size()){
//		while (1){
//			cout << "aaaaaa\n";
//		}
//	}
}
void down(int x, int fa, int id, double mul){
//	if (apls[fa].size() != v[fa].size()){
//		while (1){
//			cout << "aaaaaa\n";
//		}
//	}
	double nxmul;
	if (fa != 0){
		double faprs = apls[fa][id] * mul;
//		cout << "x,faprs,prs: " << x << ',' << faprs << ',' << prs << '\n'; 
		nxmul = 1 - (1 - faprs) * (1 - p[fa][id]);
		ansp[x] *= nxmul;
	} 
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] != fa){
//			cout << p[x][i] << '\n';
			down(v[x][i], x, i, nxmul);
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back(y);
		v[y].push_back(x);
		p[x].push_back(1 - w * 0.01);
		p[y].push_back(1 - w * 0.01); 
	}
	for (int i = 1; i <= n; i++){
		cin >> dirp[i];
		dirp[i] *= 0.01;
		dirp[i] = 1 - dirp[i];
	}
	up(1, 0);
//	for (int i = 1; i <= n; i++){
//		for (int j = 0; j < apls[i].size(); j++)
//			cout << apls[i][j] << ' ';
//		cout << '\n';
//	}
	down(1, 0, 0, 1);
	double ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (1 - ansp[i]);
	printf("%.6lf", ans);
	return 0;
}

