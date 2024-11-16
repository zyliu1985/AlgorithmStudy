#include <iostream>
#include <algorithm>
#include <cmath>
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
inline void write(int x, char end = 0){
	if (x < 0){
		putchar('-');
		write(-x);
		return;
	}
	int len = x ? 0 : 1, tx = x;
	while (x > 0){
		x /= 10;
		len++;
	}
	while (len--){
		putchar(tx / pow(10, len) + '0');
		tx %= int(pow(10, len));
	}
	putchar(end);
}
string s[200005];
bool cmp(string a, string b){
	return a + b < b + a;
}
int main(){
	freopen("bead.in", "r", stdin);
	freopen("bead.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s+1, s+n+1, cmp);
	for (int i = 1; i <= n; i++)
		cout << s[i];
	return 0;
}
