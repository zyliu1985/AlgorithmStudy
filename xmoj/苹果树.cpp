#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, f[105], ch[105][2], dp[105][105];
int apple[105][105];
void dfs(int x, int fa){
//	cout << x << ' ' << fa << '\n';
	f[x] = fa;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (i != fa && apple[x][i] != -1){
			ch[x][cnt++] = i;
			dfs(i, x);
		}
}
void adp(int x, int num){
	if (num <= 0) return;
	if (ch[x][0] == 0 && ch[x][1] == 0) return;
	if (dp[x][num]) return;
	adp(ch[x][0], num - 1); // 只选左
	dp[x][num] = max(dp[x][num], dp[ch[x][0]][num-1] + apple[x][ch[x][0]]); 
	adp(ch[x][1], num - 1); // 只选右
	dp[x][num] = max(dp[x][num], dp[ch[x][1]][num-1] + apple[x][ch[x][1]]); 
	for (int i = 0; i <= num - 2; i++){
		adp(ch[x][0], i);
		adp(ch[x][1], num - 2 - i);
		dp[x][num] = max(dp[x][num], dp[ch[x][0]][i] + dp[ch[x][1]][num-2-i] + apple[x][ch[x][0]] + apple[x][ch[x][1]]);
	}
//	cout << x << ' ' << num << ':' << dp[x][num] << ':' << ch[x][0] << ',' << ch[x][1] << '\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    memset(apple, -1, sizeof(apple));
	int q;
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		int x, y, a;
		cin >> x >> y >> a;
		apple[x][y] = a;
		apple[y][x] = a;
	}
	dfs(1, 0);
	adp(1, q);
	cout << dp[1][q] << '\n';
	return 0;
}



