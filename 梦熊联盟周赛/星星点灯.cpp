#include <iostream>
#include <cstring>
using namespace std;

int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
	return x * f;
}
int f[1005][1005], dis[1005], m, n;
bool vis[1005];
int prim(){
	dis[0] = 1e9;
	for (int i = 1; i <= n; i++)
		dis[i] = m;
	int ans = 0;
	for (int _ = 1; _ <= n; _++){
		int from = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dis[i] < dis[from])
				from = i;
		vis[from] = true;
		ans += dis[from];
		for (int to = 1; to <= n; to++)
			if (!vis[to] && dis[to] > f[from][to])
				dis[to] = f[from][to];
	}
	return ans;
}
int main(){
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	m = read(), n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = read();
	cout << prim() << endl;
	return 0;
} 
