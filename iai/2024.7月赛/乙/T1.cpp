#include <iostream>
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
int c;
long long qpow(long long di, long long up){
	if (up == 0) return 1;
	if (up & 1) return qpow((di * di) % c, up / 2) * di % c;
	else qpow((di * di) % c, up / 2);
}
int main(){
	cout.tie(0);
	int a = read();
	long long b = read();
	c = read();
	cout << qpow(a, b) << endl;
	return 0;
}
