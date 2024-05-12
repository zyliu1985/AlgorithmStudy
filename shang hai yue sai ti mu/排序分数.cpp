#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int fm, fz;
	double num;
} x[250005];
bool cmp(node x, node y){
	return x.num < y.num;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
int main(){
	int n, cur = 0;
	cin >> n;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++){
			if (gcd(i, j) != 1) continue;
			cur++;
			x[cur].num = i * 1.0 / j;
			x[cur].fm = i;
			x[cur].fz = j;
		}
	sort(x+1, x+cur+1, cmp);
	for (int i = 1; i <= cur; i++)
		cout << x[i].fm << '/' << x[i].fz << endl;
	return 0;
}