#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[20][20];
int f[1 << 20][20];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, st;
	cin >> n >> st;
	n++;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			cin >> dist[i][j];
	memset(f, 0x3f, sizeof(f));
	f[1][0] = st;
	for (int i = 3; i < (1 << n); i += 2)
		for (int j = 1; j < n; j++){
			if ((i >> j) & 1){
				int s = i - (1 << j);
                for (int k = 0; k < n; k++)
					if ((s >> k) & 1){
						f[i][j] = min(f[i][j], f[s][k] + dist[k][j]);
					}
			}
		}
	int ans = 1e9;
	for (int i = 1; i < n; i++)
		ans = min(ans, f[(1 << n) - 1][i]);
	cout << ans << '\n';
	return 0;
}



