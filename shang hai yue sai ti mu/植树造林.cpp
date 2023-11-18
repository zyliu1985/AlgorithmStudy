#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int maxn = 0;
	maxn = max(maxn, a);
	maxn = max(maxn, b);
	maxn = max(maxn, c);
	cout << (maxn-a) + (maxn-b) + (maxn-c) << endl;
	return 0;
}