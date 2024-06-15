#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string s1, s2;
int f[1005][1005];
struct node{
	int x, y;
} way1[1005], way2[1005];
int way(int a, int b){
	return pow(way1[a].x - way2[b].x, 2) + pow(way1[a].y - way2[b].y, 2);
}
int main(){
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++){
		way1[i] = node{x1, y1};
		if (s1[i] == 'N') y1++;
		if (s1[i] == 'S') y1--;
		if (s1[i] == 'W') x1--;
		if (s1[i] == 'E') x1++;
	}
	way1[n] = node{x1, y1};
	for (int i = 0; i < m; i++){
		way2[i] = node{x2, y2};
		if (s2[i] == 'N') y2++;
		if (s2[i] == 'S') y2--;
		if (s2[i] == 'W') x2--;
		if (s2[i] == 'E') x2++;
	}
	way2[m] = node{x2, y2};
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++){
			if (i < n) f[i+1][j] = min(f[i+1][j], f[i][j] + way(i+1, j));
			if (j < m) f[i][j+1] = min(f[i][j+1], f[i][j] + way(i, j+1));
			if (i < n && j < m) f[i+1][j+1] = min(f[i+1][j+1], f[i][j] + way(i+1, j+1));
		}
	cout << f[n][m] << endl;
	return 0;
}