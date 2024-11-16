#include <iostream>
#include <cmath>
using namespace std;

//inline int read(){
//	int re = 0, type = 1;
//	char c = getchar();
//	while (c < '0' || c > '9'){
//		if (c == '-') type = -1;
//		c = getchar();
//	}
//	while (c >= '0' && c <= '9'){
//		re = (re << 1) + (re << 3) + (c - '0');
//		c = getchar();
//	}
//	return re * type;
//}
//inline void write(int x, char end = 0){
//	if (x < 0){
//		putchar('-');
//		write(-x);
//		return;
//	}
//	int len = x ? 0 : 1, tx = x;
//	while (x > 0){
//		x /= 10;
//		len++;
//	}
//	while (len--){
//		putchar(tx / pow(10, len) + '0');
//		tx %= int(pow(10, len));
//	}
//	putchar(end);
//}
int cnt[3][10];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	string a, b, c;
	cin >> a >> b >> c;
	switch (a[1]){
		case 'm': cnt[0][a[0] - '0']++; break;
		case 'p': cnt[1][a[0] - '0']++; break;
		case 's': cnt[2][a[0] - '0']++; break;
	}
	switch (b[1]){
		case 'm': cnt[0][b[0] - '0']++; break;
		case 'p': cnt[1][b[0] - '0']++; break;
		case 's': cnt[2][b[0] - '0']++; break;
	}
	switch (c[1]){
		case 'm': cnt[0][c[0] - '0']++; break;
		case 'p': cnt[1][c[0] - '0']++; break;
		case 's': cnt[2][c[0] - '0']++; break;
	}
	// ¿Ì×Ó
	int ans = 1e9;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= 9; j++)
			ans = min(ans, 3 - cnt[i][j]);
	// Ë³×Ó
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= 7; j++)
			ans = min(ans, 3 - bool(cnt[i][j]) - bool(cnt[i][j+1]) - bool(cnt[i][j+2]));
	cout << ans << endl;
	return 0;
}
