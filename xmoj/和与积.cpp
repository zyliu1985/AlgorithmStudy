#include <iostream>
#include <algorithm>
using namespace std;

__int128 read(){
	__int128 x = 0;
	int f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') f = -1;
		c = getchar(); 
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
void write(__int128 x){
	if (x < 0) putchar('-'), write(-x);
	else if (x > 9) write(x / 10), putchar(x % 10 + '0');
	else putchar(x + '0');
}
__int128 gcd(__int128 a, __int128 b){
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
	__int128 a, b;
	a = read(), b = read();
	write(gcd(a+b, a*b));
	return 0;
}



