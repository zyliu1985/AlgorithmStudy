#include <bits/stdc++.h>
using namespace std;
int n, m, g[100010], ans;
bool f[100010]; 
int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> g[i];
	for (int i = 1; i <= m; i++){
		for (int j = g[i]; j >= 1; j--){
//			cout << g[i] << " " << j << " " << f[j] << endl;
			if (f[j] == 0){
				f[j] = 1;
				ans++;
				break;
			}
		}
		if (ans != i)
			break;
	}
	cout << ans << endl;
	return 0;
}
