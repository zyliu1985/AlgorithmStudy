#include <iostream>
#include <algorithm>
using namespace std;
void __write(int x){
	if (x < 0){
  		putchar('-');
		__write(-x);
		return;
	}
	if (x > 9) __write(x / 10);
	putchar(x % 10 + '0');
}
void __write(long long x){
  	if (x < 0){
  		putchar('-');
		__write(-x);
		return;
	}
	if (x > 9) __write(x / 10);
	putchar(x % 10 + '0');
}
int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return x * f;
}
long long READ(){
	long long x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return x * f;
}
void write(int x, char c = '\n'){
	__write(x);
	putchar(c);
}
void write(long long x, char c = '\n'){
	__write(x);
	putchar(c);
}
void endl(){
	putchar('\n');
}
bool f[405][405];
int s[405];
int main(){
	int n = read(), ans = 0;
	for (int i = 1; i <= n; i++){
		int a = read();
		s[i] = s[i-1] + a;
		f[i][i] = true;
		ans = max(ans, a);
	}
	for (int len = 2; len <= n; len++)
		for (int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			// 分成2个（直接二分查找） 
			int sum = s[r] - s[l-1];
			if (!(sum & 1)){
				int t = lower_bound(s+l, s+r+1, sum / 2 + s[l-1]) - s;
				if (s[t] == sum / 2 + s[l-1] && f[l][t] && f[t+1][r]){
					f[l][r] = true;
					ans = max(ans, sum);
					continue;
				}	
			}
			// 分成3个
			for (int k = l; k < r - 1; k++){
				int sum2 = s[k] - s[l-1];
				int t = lower_bound(s+k+1, s+r+1, s[r] - sum2) - s;
				if (s[t] == s[r] - sum2 && f[l][k] && f[k+1][t] && f[t+1][r]){
					f[l][r] = true;
					ans = max(ans, s[r] - s[l-1]);
					break;
				}
			} 
		}
	write(ans);
	return 0;
}


