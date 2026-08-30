#include <iostream>
#include <cstring>
using namespace std;

int mp[4005][4005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				char c;
				cin >> c;
				if (c == 'B') mp[i][j] = 2;
				else if (c == 'G') mp[i][j] = 1;
				else mp[i][j] = 0;
			}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (mp[i][j] == 2){
					if (i > b && j > a && mp[i-b][j-a] > 0){
						mp[i][j]--;
						mp[i-b][j-a]--;
						ans++;
					} else {
						ans = -1;
						break;
					}
				}
			}
			if (ans == -1) break;
		}
		if (ans != -1){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					if (mp[i][j] == 1){
						if (i+b <= n && j+a <= n && mp[i+b][j+a] > 0){
							mp[i][j]--;
							mp[i+b][j+a]--;
							ans++;
						} else {
							mp[i][j]--;
							ans++;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
