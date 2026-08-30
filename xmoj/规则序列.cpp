#include <iostream>
#include <algorithm>
using namespace std;

long long c[35][35];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		c[i][0] = c[i][i] = 1;
		cout << "1 ";
		for (int j = 1; j < i; j++){
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			cout << c[i][j] << ' ';
		}
		if (i != 0) cout << "1\n";
		else cout << '\n';
	}
	return 0;
}



