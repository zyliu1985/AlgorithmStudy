#include <iostream>
using namespace std;

int main(){
	int n, m, n1, n2, m1, m2;
	cin >> n >> m >> n1 >> n2 >> m1 >> m2;
	for (int i = 1; i <= n; i++){
		bool flag = false;
		for (int j = 1; j <= m; j++){
			int t;
			cin >> t;
			if (i >= n1 && i <= n2 && j >= m1 && j <= m2){
				cout << t << ' ';
				flag = true;
			}
		}
		if (flag) cout << endl;
	}
	return 0;
}