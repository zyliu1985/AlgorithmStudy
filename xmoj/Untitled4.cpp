#include <iostream>
#include <algorithm>
using namespace std;

int f[105][105];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n = 20;
	for (int i = 0; i < n; i++){
		f[i][0] = 1, f[i][i] = 1;
		for (int j = 1; j < i; j++)
			f[i][j] = f[i-1][j-1] + f[i-1][j];
			
			for (int j = 0; j <= i; j++)
				cout << (f[i][j] & 1) << '\t';
			cout << '\n'; 
	}
	cout << '\n';
	return 0;
}



