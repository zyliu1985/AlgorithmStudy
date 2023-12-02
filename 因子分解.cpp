#include <iostream>
#include <cmath>
using namespace std;

bool check(int x){
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++){
		if (x % i == 0) return false;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	int t = 2;
	while (n > 1){
		if (n % t != 0 || !check(t)){
			t++;
			continue;
		}
		n /= t;
		cout << t << ' ';
	}
	return 0;
}