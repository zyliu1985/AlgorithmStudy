#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
long long w[2505], dis[2505]; // w代表每一个点的价值，dis代表每一个点的距离
__int128 ans; // ans可能会炸，要开__int128
vector<int> v[2505]; // v存图
vector<long long> f[2505]; // f[x]存x和1都可转k次车以内到达的价值最大的3个节点
queue<int> q; // bfs队列
bool to[2505][2505]; // to[i][j]代表i,j是否可转k次车以内到达
bool cmp(int x, int y){
	return w[x] > w[y];
}
void bfs(int x){
	memset(dis, -1, sizeof(dis)); // 初始化
	q.push(x);
	dis[x] = 0;
	while (!q.empty()){
		int y = q.front();
		q.pop();
		if (y != x){ // 由于点不能重复，所以我们判定自己和自己不可达
			to[x][y] = true; // 标记
			if (x != 1 && to[1][y] == true){ // 由于1节点不需要更新f数组，所以这边判一下x不等于1
				f[x].push_back(y);
				sort(f[x].begin(), f[x].end(), cmp);
				if (f[x].size() > 3) f[x].pop_back();
			}
		}
		if (dis[y] == k + 1) continue; // 如果已经转了k次车（走了k+1条边）就不能更新其他点了
		for (int i = 0; i < v[y].size(); i++)
			if (dis[v[y][i]] == -1){ // vis,dis二合一
				dis[v[y][i]] = dis[y] + 1;
				q.push(v[y][i]);
			}
	}
}
void print(__int128 x){
	string s;
	while (x > 0){
		s = char(x % 10 + '0') + s;
		x /= 10;
	}
	cout << s;
}
int main(){
	// 读入
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	// 制造to和f
	for (int i = 1; i <= n; i++)
		bfs(i);
	// 暴力n^2枚举b和c点
	for (int b = 2; b <= n; b++)
		for (int c = 2; c <= n; c++)
			if (to[b][c]) // b,c要可达
				// 枚举a,d,由于只许要枚举3*3个（或更少，原因见上文）时间复杂度可以忽略不计
				for (int ida = 0; ida < f[b].size(); ida++)
					for (int idd = 0; idd < f[c].size(); idd++){
						long long a = f[b][ida];
						long long d = f[c][idd];
						if (a != d && a != c && d != b)
							if (w[a] + w[b] + w[c] + w[d] > ans)
								ans = w[a] + w[b] + w[c] + w[d];
					}
	print(ans);
	return 0;
}