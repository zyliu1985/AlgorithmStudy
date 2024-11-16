#include <iostream>
#include <cmath>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int main(){
	cout.tie(0);
	int a = read(), b = read(), x = read(), y = read();
	cout << min(abs(a - b), min(abs(a - x) + abs(y - b), abs(a - y) + abs(x - b))) << '\n';
	return 0;
}
