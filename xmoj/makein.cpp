#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

mt19937 mt(19249);
int main(){
	freopen("query.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << 100000 << ' ' << 100000 << '\n';
	for (int i = 1; i<= 1e5; i++)
		cout << mt() % 1000000000 << ' ';
	cout << '\n';
	for (int i = 1; i <= 1e5; i++){
		int l = mt() % 50000 + 1;
		int r = mt() % 50000 + l;
		cout << 1 << ' ' << l << ' ' << r << ' ' << mt() % 1000000000 << '\n';
	}
	return 0;
}

