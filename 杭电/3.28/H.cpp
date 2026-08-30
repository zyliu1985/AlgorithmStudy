#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> f;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
	while (t--){
		f.clear();
		int n, k;
		cin >> n >> k;
		f.resize(n+1);
		f[0].resize(k+1);
		for (int i = 1; i <= n; i++){
			f[i].resize(k+1);
			for (int j = 1; j <= k; j++){
				int a;
				cin >> a;
				f[i][j] = max(f[i][j-1], f[i-1][j] + a);
			}
		}
		cout << f[n][k] <<'\n';
	}
	return 0;
}



