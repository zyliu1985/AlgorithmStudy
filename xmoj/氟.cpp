#include <iostream>
#include <algorithm>
using namespace std;

__int128 read(){
	__int128 re = 0;
	char c;
	c = getchar();
	while (c < '0' || c > '9'){
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re;
}
void write(__int128 x){
	if (x == 0) return;
	write(x / 10);
	putchar(x % 10 + '0');
}
__int128 pow2(__int128 x){
	__int128 re = 1;
	for (int i = 1; i <= x; i++)
		re *= 2;
	return re;
}
int main(){
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	__int128 h, m, n;
	h = read(), m = read(), n = read();
	for (int i = 1; i <= m; i++)
		read();
	write((m * n + pow2(h) - 1) / pow2(h));
	return 0;
}

