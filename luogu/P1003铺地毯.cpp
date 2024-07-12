#include <iostream>
using namespace std;

struct node{
	int x1, y1, x2, y2;
} g[10005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> g[i].x1 >> g[i].y1 >> a >> b;
		g[i].x2 = g[i].x1 + a;
		g[i].y2 = g[i].y1 + b;
	}
	int x, y;
	cin >> x >> y;
	for (int i = n; i >= 1; i--)
		if (g[i].x1 <= x && x <= g[i].x2 && g[i].y1 <= y && y <= g[i].y2){
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}