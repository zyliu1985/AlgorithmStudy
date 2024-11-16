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
int main(){
	cout.tie(0);
	int m = read(), last = read();
	for (int i = 2; i <= m; i++)
		if (read() != last){
			cout << m - 1 << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}
