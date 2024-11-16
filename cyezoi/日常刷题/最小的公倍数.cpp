#include <iostream>
#include <cstdio>
using namespace std;

int a[100005];
int Big_mod(int x){
	int last = 0;
	for (int i = 1; i <= a[0]; i++){
		last = last * 10 + a[i];
		last %= x;
	}
	return last;
}
int main(){
	int l;
	cin >> l;
	if (l < 3){
		cout << -1 << endl;
		return 0;
	}
	if (l == 3){
		cout << 210 << endl;
		return 0;
	}
	a[0] = l;
	cout << 1;
	for (int i = 2; i <= l; i++){
		a[i] = 0;
		if (i < l-2) cout << 0;
	}
	a[1] = 1;
	int x = Big_mod(210);
	x = 210 - x;
	if (x == 0) cout << "000" << endl;
	else if (x > 0 && x < 10) cout << "00" << x << endl;
	else if (x > 9 && x < 100) cout << "0" << x << endl;
	else cout << x << endl;			
	return 0;
}