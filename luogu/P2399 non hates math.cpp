#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int siz[3];
long long x[3];
long long a, b;
long long gcd(long long a, long long b){
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	int now = 0;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9') x[now] = x[now] * 10 + s[i] - '0', siz[now]++;
		else now++;
//		cout << now << '\n';
	}
	b = max(int((pow(10, siz[2]) - 1)), 1) * pow(10, siz[1]);
	a = x[0] * b + x[1] * max(int((pow(10, siz[2]) - 1)), 1) + x[2];
//	cout << a << ' ' << b << '\n';
	cout << a / gcd(a, b) << '/' << b / gcd(a, b) << '\n';
	return 0;
}



