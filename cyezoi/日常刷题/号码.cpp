#include <iostream>
using namespace std;

string s;
bool check(int x){
	int a, b, c, d;
	a = x / 1000;
	b = x / 100 % 10;
	c = x / 10 % 10;
	d = x % 10;
	for (int i = 0; i <= 9; i++){
		if (s[i] == 'o') if (a != i && b != i && c != i && d != i) return false;
		if (s[i] == 'x') if (a == i || b == i || c == i || d == i) return false;
	}
	return true;
}
int main(){
	cin >> s;
	int cnt = 0, ans = 0;
	while (ans <= 9999){
		if (check(ans)) cnt++;
		ans++;
	}
	cout << cnt << endl;
	return 0;
}