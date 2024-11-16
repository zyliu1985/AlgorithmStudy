#include <iostream>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
int a[100005];
long long gcd(long long x, long long y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
int main(){
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	int n = read();
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		a[i] = read();
		sum += a[i];
	}
	long long lft = 0, rgt = sum, ans = 0;
	for (int i = 1; i < n; i++){
		lft += a[i];
		rgt -= a[i];
		ans = max(ans, gcd(lft, rgt));
	}
	cout << ans << endl; 
	return 0;
}
