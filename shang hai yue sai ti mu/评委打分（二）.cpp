#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double n, a, b, c;
	cin >> n >> a >> b >> c;
	double ans = ((a+c)*(n-1) - b*n) / (n-2);
	printf("%.2f", ans);
	return 0;
}