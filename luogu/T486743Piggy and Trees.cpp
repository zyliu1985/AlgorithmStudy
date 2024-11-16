#include <iostream>
#include <vector>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int near_father[3005][3005], dis[3005][3005], side1[3005], side2[3005];
int depth[3005];
vector<int> v[3005];
void make_depth(int x){
	for (int i = 0; i < v[x].size(); i++)
		if (depth[v[x][i]] == 0){
			depth[v[x][i]] = depth[x] + 1;
			make_depth(v[x][i]);
		}
}
void make_dis_and_father(int x, int last, int from){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != last){
			dis[from][v[x][i]] = dis[from][x] + 1;
			if (depth[near_father[from][x]] < depth[v[x][i]])
				near_father[from][v[x][i]] = near_father[from][x];
			else
				near_father[from][v[x][i]] = v[x][i];
			make_dis_and_father(v[x][i], x, from);
		}
}
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i < n; i++){
		int a = read(), b = read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	depth[1] = 1;
	make_depth(1);
	for (int i = 1; i <= n; i++){
		dis[i][i] = 0;
		near_father[i][i] = i;
		make_dis_and_father(i, 0, i);
	}
	cout << "dis:" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << dis[i][j] << ' ';
		cout << endl;
	}
	cout << "nf:" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << near_father[i][j] << ' ';
		cout << endl;
	}
	int ans = 0, mod = 1e9 + 7;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			for (int k = 1; k <= n; k++){
				if (dis[i][k] + dis[k][near_father[i][j]] == dis[i][near_father[i][j]] || dis[j][k] + dis[k][near_father[i][j]] == dis[j][near_father[i][j]])
					continue;
				ans = (ans + min(dis[near_father[i][j]][k], min(dis[i][k], dis[j][k]))) % mod;
			}
	cout << ans << endl;
	return 0;
}
