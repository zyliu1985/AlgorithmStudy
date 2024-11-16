#include <iostream>
#include <cmath> 
using namespace std;

int d, n;
bool is_su(int x){
	for (int i = 2; i <= sqrt(x); i++)
		if (x / i == (x + i - 1) / i) return false;
	return true;
}
int mpo(int x, int up){
	int re = 1;
	while (up--)
		re *= x;
	return re;
}
bool check(int x){
	int y = 0, i;
	bool flag = false;
	for (i = 1; i <= d; i++){
		flag = (x / 10 == (x + 9) / 10);
		y += (x % 10) * mpo(10, i - 1);
		x /= 10;
	}
	while (x >= mpo(10, d - 1)){
//		cout << x << ' ' << y << endl;
		if (!flag && is_su(x) && is_su(y)) return true;
		flag = (x / 10 == (x + 9) / 10);
		y += (x % 10) * mpo(10, i - 1);
		x /= 10;
		i++;
	}
	return false;
}
int main(){
	cin >> d >> n;
	int len = 0;
	int tn = n;
	while (tn > 0) tn /= 10, len++;
	if (d > len / 2) n = mpo(10, 2 * d - 1);
	while (114514){
		if (check(n)) break;
		n++;
	}
	cout << n << endl;
	return 0;
}
