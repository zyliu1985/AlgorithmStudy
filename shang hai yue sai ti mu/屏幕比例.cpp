#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int x, int y){
	if (x % y == 0) return y;
	else return gcd(y, x%y);
}
int main(){
	int x, y;
	scanf("%d*%d", &x, &y);
	int g = gcd(x, y);
	cout << x/g << ':' << y/g << endl;
	return 0;
}