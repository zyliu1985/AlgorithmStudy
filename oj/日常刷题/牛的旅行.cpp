#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

double d[155][155], zj[155];
int x[155], y[155], cnt, id[155], n;
double edge_size(int a, int b){
	return sqrt(pow(x[a]-x[b], 2) + pow(y[a]-y[b], 2));
}
void dfs(int now, int nid){
	id[now] = nid;
	for (int i = 1; i <= n; i++)
		if (d[now][i] > 0 && d[now][i] < 1e9 && !id[i])
			dfs(i, nid);
}
void floyd(){
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
double find_maxd(int a){
	double re = 0;
	for (int i = 1; i <= n; i++)
		if (id[i] == id[a]) re = max(re, d[a][i]);
	return re;
}
int main(){
	for (int i = 1; i <= 150; i++)
		for (int j = 1; j <= 150; j++){
			if (i == j) d[i][j] = 0;
			else d[i][j] = 1e9;
		}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char c;
			cin >> c;
			if (c == '1')
				d[i][j] = edge_size(i, j);
		}
	for (int i = 1; i <= n; i++)
		if (!id[i])
			dfs(i, ++cnt);
	floyd();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (id[i] == id[j])
				zj[id[i]] = max(zj[id[i]], d[i][j]);
	double ans = 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (id[i] == id[j]) continue;
			ans = min(ans, max(zj[id[i]], max(zj[id[j]], find_maxd(i) + find_maxd(j) + edge_size(i, j))));
		}
	printf("%.6f", ans);
	return 0;
}