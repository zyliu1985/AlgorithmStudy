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
int m;
int q_pow(int x, int up){
	if (up == 0) return 1 % m;
	if (up & 1) return q_pow(x * x % m, up / 2) * x % m;
	else return q_pow(x * x % m, up / 2);
}
int main(){
	freopen("2025.in", "r", stdin);
	freopen("2025.out", "w", stdout); 
	m = read();
	write((q_pow(2025 * 2025 % m, 2025) + 2025) % m);
	return 0;
}


