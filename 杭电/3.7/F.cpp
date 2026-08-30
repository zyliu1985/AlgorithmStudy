#include <iostream>
#include <cmath>
using namespace std;

int x1, x2, x3;
bool x1c, x2c, x3c;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int u, v, w, a, b, c;
			cin >> u >> v >> w;
			if (abs(v - w) % abs(u) == 0) a = abs(v - w) / abs(u);
			else a = -1;
			if (abs(u - w) % abs(v) == 0) b = abs(u - w) / abs(v);
			else b = -1;
			if (abs(u - v) % abs(w) == 0) c = abs(u - v) / abs(w);
			else c = -1;
			if (i == 1){
				x1 = a, x2 = b, x3 = c;
				x1c = (x1 != -1), x2c = (x2 != -1), x3c = (x3 != -1);
			} else {
				if (a != x1 && b != x1 && c != x1) x1c = false;
				if (a != x2 && b != x2 && c != x2) x2c = false;
				if (a != x3 && b != x3 && c != x3) x3c = false;
			}
		}
		if (x1c) cout << x1 << '\n';
		else if (x2c) cout << x2 << '\n';
		else if (x3c) cout << x3 << '\n';
	} 
	return 0;
}


