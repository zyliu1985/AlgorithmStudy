#include <iostream>
using namespace std;

int read(){
	int re = 0, type = 1;
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
int a[200005];
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	int ans = 0, sum = 0;
	for (int i = 1; i <= n; i++){
		sum += a[i];
		if (sum >= 0)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}
