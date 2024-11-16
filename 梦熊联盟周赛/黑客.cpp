#include <iostream>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int allsum, sum1, pos1, sum2, pos2, a[500005], sna = 1e9;	
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++){
		a[i] = read();
		allsum += a[i];
	}
	for (int i = 2; i <= n / 2 + 1; i++)
		sum1 += a[i];
	pos1 = n / 2 + 1;
	for (int i = n; i >= (n + 1) / 2 + 1; i--)
		sum2 += a[i];
	pos2 = (n + 1) / 2 + 1;
	for (int i = 1; i <= n; i++){
//		cout << "i:" << i << "   sum:" << sum1 << " pos:" << pos1 << "  sum:" << sum2 << " pos:" << pos2 << endl;
		sna = min(sna, max(sum1, sum2));
		sum1 -= a[i+1];
		pos1 = pos1 % n + 1;
		sum1 += a[pos1];
		sum2 -= a[pos2];
		pos2 = pos2 % n + 1;
		sum2 += a[i];
	}
	cout << allsum - sna << endl;
	return allsum - sna;
}
/*
7
1 1 1 1 100 100 100
*/
