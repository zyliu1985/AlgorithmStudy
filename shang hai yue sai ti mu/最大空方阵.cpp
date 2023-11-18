#include <iostream>
using namespace std;

int a[3005][3005], n, maxn;
bool vis[3005][3005];
int fun(int x, int y){
	int t = 1;
	vis[x][y] = true;
	while (a[x][y+t] == 0){
		for (int i = x; i <= x+t; i++){
			if (a[i][y+t] == 1) return t-1;
			else vis[i][y+t] = true;
		}
		t++;
	}
	return t-1;
} 

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i][j] == 0) maxn = max(fun(i, j), maxn);
		}
	}
	cout << maxn << endl;
	return 0;
}