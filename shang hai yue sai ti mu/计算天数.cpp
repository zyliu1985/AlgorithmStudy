#include <iostream>
#include <cstdio>
using namespace std;

int D[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int main(){
	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		for (int i = 3; i <= 12; i++) D[i]++;
	cout << D[m]+d << endl;
	return 0;
}