#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int a[200005];
long long dp[200005];
long long s[1005][1005];
int n;
void insert(int x){
	for (int i = 1; i <= 1000; i++)
		s[i][x % i] = (s[i][x % i] + dp[x]) % mod;
}
int query(int st, int jump){
	if (jump <= 1000){
		return s[jump][st % jump];
	} else {
		long long re = 0;
		for (int i = st + jump; i <= n; i += jump)
			re = (re + dp[i]) % mod;
		return re;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[n] = 1;
	insert(n); 
	for (int i = n-1; i >= 1; i--){
		dp[i] = (1 + query(i, a[i])) % mod;
		insert(i);
	}
	cout << dp[1] << '\n';
	return 0;
}

