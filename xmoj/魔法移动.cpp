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
const int mod = 1e9 + 7;
long long c[105][105];
int magic[7], x, y, n;
struct node{
	long long dx, dy, n;
} a[7];
long long ans = 0;
void dfs(long long nx, long long ny, int id, int num){
	if (id > n){
		if (nx != x || ny != y) return;
		long long now = 1;
		for (int i = 1; i <= n; i++){
			now = (now * c[num][magic[i]]) % mod;
			num -= magic[i];
		}
		ans = (ans + now) % mod;
		return;
	}
	for (int i = 0; i <= a[id].n; i++){
		magic[id] = i;
		dfs(nx + a[id].dx * i, ny + a[id].dy * i, id + 1, num + i);
	}
}
int main(){
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout);
	for (int i = 0; i <= 100; i++){
		c[i][0] = 1, c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
	}
	x = read(), y = read(), n = read();
	for (int i = 1; i <= n; i++)
		cin >> a[i].dx >> a[i].dy >> a[i].n;
	dfs(0, 0, 1, 0);
	write(ans);
	return 0;
}


