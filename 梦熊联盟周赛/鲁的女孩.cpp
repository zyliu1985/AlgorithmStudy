#include <iostream>
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
int cntA[105], cntB[105];
int solve(){
	int re = 0;
	int i = 1, j = 100;
	int anum = cntA[i], bnum = cntB[j];
	while (i <= 100 && j >= 1){
		while (anum == 0 && i <= 100)
			anum = cntA[++i];
		while (bnum == 0 && j >= 1)
			bnum = cntB[--j];
//		cout << i << ' ' << j << endl;
		if (i > 100 || j < 1) break;
		re = max(re, i + j);
		if (anum > bnum){
			anum -= bnum;
			bnum = 0;
		} else {
			bnum -= anum;
			anum = 0;
		}
	}
	return re;
}
int main(){
	freopen("girl.in", "r", stdin);
	freopen("girl.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++){
		int a = read(), b = read();
		cntA[a]++;
		cntB[b]++;
		write(solve(), '\n');
	}
	return 0;
}
