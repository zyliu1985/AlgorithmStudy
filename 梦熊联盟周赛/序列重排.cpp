#include <iostream>
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
int maxn, num0;
int main(){
	freopen("arrange.in", "r", stdin);
	freopen("arrange.out", "w", stdout); 
	int n = read();
	for (int i = 1; i <= n; i++){
		int a = read();
		maxn = max(maxn, a);
		num0 += (a == 0);
	}
	if (num0 <= (n + 1) / 2)
		cout << 0 << endl;
	else if (maxn != 1)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	return 0;
}
