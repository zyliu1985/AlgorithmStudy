#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
bool a[25][25];
long long dp[1 << 22];
int calc(int x){
	int re = 0;
	while (x > 0){
		re++;
		x -= (x&-x);
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	dp[0] = 1;
	for (int i = 1; i < (1 << n); i++){
		int x = calc(i);
		for (int j = 1; j <= n; j++){
			if (a[x][j] && ((i >> (j-1)) & 1))
				dp[i] = (dp[i] + dp[i ^ (1 << (j-1))]) % mod;
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}

