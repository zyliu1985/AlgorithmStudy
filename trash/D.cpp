#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1505][1505];
long long s[1505][1505];
long long v[1505][1505];
long long dp[1505][1505]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j] = s[i][j-1] + s[i-1][j] + a[i][j] - s[i-1][j-1];
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++){
			v[i][j] = v[j][i] = s[i][j-1] - s[i][i-1] + s[j][n] - s[i][n] - s[j][j-1] + s[i][j-1];
		}
//	for (int i = 1; i <= n; i++)
//		for (int j = i+1; j <= n; j++){
//			int now = 0;
//			for (int l = 1; l <= i; l++)
//				for (int r = i; r <= j-1; r++)
//					now += a[l][r];
//			for (int l = i+1; l <= j; l++)
//				for (int r = j; r <= n; r++)
//					now += a[l][r];
//			v[i][j] = v[j][i] = now; 
//		}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++)
//			cout << v[i][j] << ' ';
//		cout << '\n'; 
//	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i < n; i++)
		dp[i][i+1] = v[i][i+1];
	for (int len = 4; len <= n; len += 2){
		for (int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			dp[l][r] = min(dp[l][r], dp[l+1][r-1] + v[l][r]);
			for (int k = l + 2; k <= r - 1; k += 2)
				dp[l][r] = min(dp[l][r], dp[l][k-1] + dp[k][r]);
//			cout << l << ',' << r << ':' << dp[l][r] << '\n'; 
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}

