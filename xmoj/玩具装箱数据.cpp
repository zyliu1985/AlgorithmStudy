#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

mt19937 m(time(0));
int main(){
	freopen("in.in", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n = m() % 10 + 1, l = m() % 100 + 1;
	cout << n << ' ' << l << '\n';
	for (int i = 1; i <= n; i++)
		cout << m() % 100 + 1 << '\n'; 
	return 0;
}



