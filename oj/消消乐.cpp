#include <iostream>
#include <cstring>
using namespace std;

char c[105][15];
bool vis[105][15], flag[105][15];
int n, k;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= 10;
}
int dfs(int x, int y){
	flag[x][y] = true;
	int sum = 1;
	vis[x][y] = true;
	if (c[x+1][y] == c[x][y] && !vis[x+1][y] && in(x+1, y))
		sum += dfs(x+1, y);
	if (c[x-1][y] == c[x][y] && !vis[x-1][y] && in(x-1, y))
		sum += dfs(x-1, y);
	if (c[x][y+1] == c[x][y] && !vis[x][y+1] && in(x, y+1))
		sum += dfs(x, y+1);
	if (c[x][y-1] == c[x][y] && !vis[x][y-1] && in(x, y-1))
		sum += dfs(x, y-1);
	return sum;
}
void clear(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++)
			if (flag[i][j]) c[i][j] = '0';
}
void down(){
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= 10; j++){
			int x = i;
			int y = j;
			while (i != n && c[x+1][y] == '0'){
				swap(c[x][y], c[x+1][y]);
				x++;
			}
		}
}
int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++)
			cin >> c[i][j];
	int l;
	do{
		l = 0;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 10; j++)
				if (!vis[i][j] && c[i][j] != '0'){
//					cout << i << ' ' << j << endl;
					if (dfs(i, j) >= k){
						l++;
						clear();
					}
					memset(flag, false, sizeof(flag));
				}
		down();
		memset(vis, false, sizeof(vis));
	} while(l > 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 10; j++)
			cout << c[i][j];
		cout << endl;
	}
	return 0;
}