#include <iostream>
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
bool x[55][55];
int main(){
	freopen("rec.in", "r", stdin);
	freopen("rec.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++){
		int u = read() + 1, v = read() + 1;
		x[u][v] = true;
		x[v][u] = true;
	}
	int ans = 0;
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++){
			if (a == b) continue;
			for (int c = 1; c <= n; c++){
				if (a == c || b == c) continue;
				for (int d = 1; d <= n; d++)
					if (a == d || b == d || c == d) continue;
					else if (x[a][b] && x[b][c] && x[c][d] && x[d][a] && (!x[a][c]) && (!x[b][d])){
						ans++;
					}
			}
		}
	write(ans / 8);
	return 0;
}


