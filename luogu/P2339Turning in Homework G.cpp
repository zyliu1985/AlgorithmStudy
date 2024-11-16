#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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
struct node{
	int t, x;
} cl[1005];
int f[1005][1005][2];
bool cmp(node x, node y){
	return x.x < y.x;
}
int main(){
	cout.tie(0);
	int c = read(), h = read(), b = read();
	for (int i = 1; i <= c; i++)
		cl[i].x = read(), cl[i].t = read();
	sort(cl+1, cl+c+1, cmp);
//	cout << endl << endl;
//	cout << "-------" << endl;
//	for (int i = 1; i <= c; i++)
//		cout << cl[i].x << ' ' << cl[i].t << endl; 
	memset(f, 0x3f, sizeof(f));
	f[1][c][0] = 0;
	for (int l = c - 1; l >= 0; l--)
		for (int i = 1; i + l - 1 <= c; i++){
			int j = i + l - 1;
			f[i][j][0] = min(max(cl[i-1].t, f[i-1][j][0] + cl[i-1].x - cl[i-2].x), max(cl[i-1].t, f[i-1][j][1] + cl[j+1].x - cl[i-1].x));
			f[i][j][1] = min(max(cl[j+1].t, f[i][j+1][1] + cl[j+2].x - cl[j+1].x), max(cl[j+1].t, f[i][j+1][0] + cl[j+1].x - cl[i-1].x));
//			cout << '(' << i << ", " << j << "):" << f[i][j][0] << ", " << f[i][j][1] << endl;
		}
	int ans = 1e9;
	for (int i = 1; i <= c + 1; i++)
		ans = min(ans, min(f[i][i-1][0] + abs(b - cl[i-1].x), f[i][i-1][1] + abs(b - cl[i].x)));
	cout << ans << endl;
	return 0;
}
