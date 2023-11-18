#include <iostream>
#include <algorithm>
using namespace std;

int a[25][25];

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	swap(a[x1][y1], a[x2][y2]);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}