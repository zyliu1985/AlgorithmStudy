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
int a[105], size[105], ans;
int main(){
	freopen("case.in", "r", stdin);
	freopen("case.out", "w", stdout); 
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	size[0] = 1e9;
	for (int i = 1; i <= n; i++){
		int target = 0;
		for (int j = 1; j <= ans; j++)
			if (size[j] <= a[i] && size[target] > size[j])
				target = j;
		if (target == 0)
			size[++ans] = 1;
		else
			size[target]++;
//		cout << i << ':' << target << endl; 
	}
//	write(n, ':');
//	for (int i = 3; i <= n; i++)
//		write(a[i], ',');
	write(ans, '\n');
	return 0;
}
/*
4
10 1 1 0 0


1
1
10 0 0

0
1  0
10 1 
*/
