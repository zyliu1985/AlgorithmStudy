#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;

mt19937 m(time(0));
int main(){
	freopen("in.in", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	cout << 10 << '\n';
	for (int i = 1; i <= 10; i++){
		int n = m() % 1000000 + 2;
		int k = m() % n + 1;
		cout << n << ' ' << k << '\n';
	}
	return 0;
}



