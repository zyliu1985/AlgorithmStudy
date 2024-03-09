#include<iostream>
using namespace std;

int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, (x%y));
}
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int c = gcd(a, b);
	int last = n % (a + b + c * 2);
	char ans = 'C';
	int aa = b / c;
	int bb = a / c;
//	cout << c << endl;
	int x = 1, y = 1;
	while (last > 0){
//		cout << ans << ' ' << last << endl;
		if (x * aa < y * bb){
			x++;
			ans = 'A';
			last--;
		} else if (y * bb < x * aa){
			y++;
			ans = 'B';
			last--;
		} else {
			x++;
			y++;
			ans = 'C';
			last -= 4;
		} 
	}
	cout << ans << endl;
	return 0;
}