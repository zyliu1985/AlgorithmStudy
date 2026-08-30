#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
char mp[25][25];
long long dp[2][25][1 << 18];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	dp[0][1][0] = 1;
	bool now = 0; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < (1 << m); k++){
//				if (dp[now][j][k]){
//					cout << i << ' ' << j << ' ';
//					print(k);
//					cout << ':' << dp[now][j][k] << '\n';
//				}
				if (mp[i][j] == '.'){
					if ((k >> (j-1)) & 1){
						dp[now][j+1][k^(1<<(j-1))] = (dp[now][j+1][k^(1<<(j-1))] + dp[now][j][k]) % mod;
					} else {
						if (mp[i][j+1] == '.' && (!((k >> j) & 1)))
							dp[now][j+2][k] = (dp[now][j+2][k] + dp[now][j][k]) % mod;
						dp[now][j+1][k|(1<<(j-1))] = (dp[now][j+1][k|(1<<(j-1))] + dp[now][j][k]) % mod;
					}
				} else if (!((k >> (j-1)) & 1)){
					dp[now][j+1][k] = (dp[now][j+1][k] + dp[now][j][k]) % mod;
				}
			}
		for (int j = 1; j <= m+1; j++)
			for (int k = 0; k < (1 << m); k++)
				dp[now^1][j][k] = 0;
		for (int k = 0; k < (1 << m); k++)
			dp[now^1][1][k] = dp[now][m+1][k];
		now ^= 1;
	}
	cout << dp[now^1][m+1][0] << '\n';	
	return 0;
}

