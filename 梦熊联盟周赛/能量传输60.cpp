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
bool x[15];
int main(){
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
	int n = read(), cnt = 0;
	for (int i = 1; i <= n; i++){
		x[i] = read();
		if (x[i]) cnt++;
	}
	if (cnt == 9){
		int ans = 0, last1 = -1, last2 = -1;
		for (int i = 1; i <= n; i++)
			if (x[i]){
				if (last1 == -1)
					last1 = i;
				else if (last2 == -1)
					last2 = i;
				else{
					ans += abs(i - last1);
					last1 = -1;
					last2 = -1;
				}
			}
		write(ans);
		return 0;
	}
	if (cnt & 1){
		int tem = 0;
		for (int i = 1; i <= n; i++)
			if (x[i]){
				tem++;
				if (tem == cnt / 2 + 1){
					tem = i;
					break;
				}
			}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (x[i]){
				ans += abs(tem - i);
				break;
			}
		for (int i = n; i >= 1; i--)
			if (x[i]){
				ans += abs(tem - i);
				break;
			}
		write(ans);
	} else {
		int ans = 0, last = -1;
		for (int i = 1; i <= n; i++)
			if (x[i]){
				if (last == -1)
					last = i;
				else{
					ans += abs(i - last);
					last = -1;
				}
			}
		write(ans);
	}
	return 0;
}
/*
7
1 1 1 1 1 1 1
*/ 
