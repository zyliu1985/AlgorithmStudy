#include <iostream>
#include <cmath>
using namespace std;

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
int n;
string s;
bool check(int limit, int x){
//	cout << limit << ' ' << x << endl;
	if (x >= n) return true;
	int sum = 0;
	for (int i = x; i < n; i++){
		sum += s[i] - '0';
		if (sum == limit){
			i++;
			while (i < n && s[i] == '0') i++;
			return check(limit, i);
		} else if (sum > limit){
			return false;
		}
//		cout << "sum=" << sum << endl;
	}
	return false;
}
int main(){
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
	while (cin >> n >> s){
		int sum = 0;
		bool flag = true;
		for (int i = 0; i < n - 1; i++){
			sum += s[i] - '0';
			if (check(sum, i + 1)){
				puts("YES");
				flag = false;
				break;
			}
		}
		if (flag) puts("NO");
	}
	return 0;
}
