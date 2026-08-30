#include <iostream>
#include <algorithm>
using namespace std;

bool c[505][505];
int s[505][505];
int calc(int x, int y){
	int re = 0;
	if (c[x][y] && c[x-1][y] && c[x-1][y-1] && c[x][y-1]) re++;
	if (c[x][y] && c[x+1][y] && c[x+1][y-1] && c[x][y-1]) re++;
	if (c[x][y] && c[x-1][y] && c[x-1][y+1] && c[x][y+1]) re++;
	if (c[x][y] && c[x+1][y] && c[x+1][y+1] && c[x][y+1]) re++;
	return re; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char x;
			cin >> x;
			c[i][j] = (x == '.');
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + calc(i, j);
		}
	while (q--){
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		int sum = s[a2-1][b2-1] - s[a1][b2-1] - s[a2-1][b1] + s[a1][b1];
		int x, y;
		for (x = a1+1; x < a2; x++){
			y = b1;
			if (c[x][y] && c[x-1][y] && c[x-1][y+1] && c[x][y+1]) sum++;
			if (c[x][y] && c[x+1][y] && c[x+1][y+1] && c[x][y+1]) sum++;
			y = b2;
			if (c[x][y] && c[x-1][y] && c[x-1][y-1] && c[x][y-1]) sum++;
			if (c[x][y] && c[x+1][y] && c[x+1][y-1] && c[x][y-1]) sum++;
		}
		for (y = b1+1; y < b2; y++){
			x = a1;
			if (c[x][y] && c[x+1][y] && c[x+1][y-1] && c[x][y-1]) sum++;
			if (c[x][y] && c[x+1][y] && c[x+1][y+1] && c[x][y+1]) sum++;
			x = a2;
			if (c[x][y] && c[x-1][y] && c[x-1][y-1] && c[x][y-1]) sum++;
			if (c[x][y] && c[x-1][y] && c[x-1][y+1] && c[x][y+1]) sum++;
		}
		x = a1, y = b1;
		if (c[x][y] && c[x+1][y] && c[x+1][y+1] && c[x][y+1]) sum++;
		y = b2;
		if (c[x][y] && c[x+1][y] && c[x+1][y-1] && c[x][y-1]) sum++;
		x = a2, y = b1;
		if (c[x][y] && c[x-1][y] && c[x-1][y+1] && c[x][y+1]) sum++;
		y = b2;
		if (c[x][y] && c[x-1][y] && c[x-1][y-1] && c[x][y-1]) sum++;
		cout << sum / 4 << '\n';
	}
	return 0;
}

