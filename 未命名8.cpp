#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

long long a[1005], c[1005][1005];

int main() {
	long long rv = 1;
	for(long long i = 1; i<=1000000000; i++) {
		rv = rv * (i % 998244353);
		rv %= 998244353;
	}
  cout << rv << endl;
	return 0;
}