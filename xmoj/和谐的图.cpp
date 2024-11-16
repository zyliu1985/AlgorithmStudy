// O(n sqrt(n) log(n))
#include <iostream>
#include <vector>
using namespace std;
 
int read(){
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
    return x*f;
}
long long READ(){
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
    return x*f;
}
void write(int x){
    if (x < 0){putchar('-'), write(-x); return;}
    if (x / 10 == 0){putchar(x + '0'); return;}
    write(x / 10);
    putchar(x % 10 + '0');
}
void write(long long x){
    if (x < 0){putchar('-'), write(-x); return;}
    if (x / 10 == 0){putchar(x + '0'); return;}
    write(x / 10);
    putchar(x % 10 + '0');
}

int size[100005], num_size[100005], things[100005], dp[100005];
bool vis[100005];
vector<int> v[100005];
void dfs(int x, int co){
    size[co]++;
    vis[x] = true;
    for (int i = 0; i < v[x].size(); i++)
        if (!vis[v[x][i]])
            dfs(v[x][i], co);
}
int main(){
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= m; i++){
        int a = read(), b = read();
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // 计算size 
    int color = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, ++color);
    // 统计
	for (int i = 1; i <= color; i++)
		num_size[size[i]]++;
	// 二进制拆分
	int cur = 0;
	for (int i = 1; i <= 1e5; i++){
		int x = 1;
		while (num_size[i] >= x){
			things[++cur] = i * x;
			num_size[i] -= x;
		}
		if (num_size[i] > 0) things[++cur] = num_size[i];
	}
	// 正常dp
	for (int i = 1; i <= n; i++)
		dp[i] = 1e9;
	dp[0] = -1;
	for (int i = 1; i <= cur; i++)
		for (int j = n; j >= things[i]; j--)
			dp[j] = min(dp[j], dp[j - things[i]] + 1);
	// 输出
	for (int i = 1; i <= n; i++)
		if (dp[i] == 1e9)
			write(-1), putchar('\n');
		else
			write(dp[i]), putchar('\n');
    return 0;
}
