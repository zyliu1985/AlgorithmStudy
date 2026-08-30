#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int Log2[1000005];
int Fmax[15][1005][1005], Fmin[15][1005][1005];
void init(){
	Log2[0] = -1;
	for (int i = 1; i <= 1e6; i++)
		Log2[i] = Log2[i / 2] + 1;
	for (int i = 1; i <= 20; i++)
		for (int x = 1; x <= a - (1 << i) + 1; x++)
			for (int y = 1; y <= b - (1 << i) + 1; y++){
				Fmax[i][x][y] = max(max(Fmax[i-1][x][y], Fmax[i-1][x][y + (1 << (i-1))]), 
									max(Fmax[i-1][x + (1 << (i-1))][y], Fmax[i-1][x + (1 << (i-1))][y + (1 << (i-1))]));
				Fmin[i][x][y] = min(min(Fmin[i-1][x][y], Fmin[i-1][x][y + (1 << (i-1))]), 
									min(Fmin[i-1][x + (1 << (i-1))][y], Fmin[i-1][x + (1 << (i-1))][y + (1 << (i-1))]));
			}
}
int quary_max(int x1, int y1, int x2, int y2){
	int k = Log2[x2 - x1 + 1];
	return max(max(Fmax[k][x1][y1], Fmax[k][x1][y2 - (1 << k) + 1]), 
			   max(Fmax[k][x2 - (1 << k) + 1][y1], Fmax[k][x2 - (1 << k) + 1][y2 - (1 << k) + 1])); 
}
int quary_min(int x1, int y1, int x2, int y2){
	int k = Log2[x2 - x1 + 1];
	return min(min(Fmin[k][x1][y1], Fmin[k][x1][y2 - (1 << k) + 1]), 
			   min(Fmin[k][x2 - (1 << k) + 1][y1], Fmin[k][x2 - (1 << k) + 1][y2 - (1 << k) + 1])); 
}
int main(){
//	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> a >> b >> n;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++){
			cin >> Fmax[0][i][j];
			Fmin[0][i][j] = Fmax[0][i][j];
		}
	init();
	int ans = 1e9;
	for (int i = 1; i <= a - n + 1; i++)
		for (int j = 1; j <= b - n + 1; j++)
			ans = min(ans, quary_max(i, j, i + n - 1, j + n - 1) - quary_min(i, j, i + n - 1, j + n - 1));
	cout << ans << '\n';
	return 0;
}



