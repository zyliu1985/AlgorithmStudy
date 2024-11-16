#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
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
inline void write(int x){
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
int main(){
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout); 
	long long sum = 0, ans = 0;
	int n = read();
	for (int i = 1; i <= n; i++){
		long long a = read();
		sum = (sum + (a * i) % mod) % mod;
		ans = (ans + sum) % mod;
	}
	write(ans);
	return 0;
}
