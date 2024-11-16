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
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	cout.tie(0);
	int t = read();
	while (t--){
		long long n = read(), k = read(), sum = 0;
		while (n > 0){
			sum += n % 3;
			n /= 3;
		}
		if (sum > k || k - sum & 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
