#include <iostream>
using namespace std;

long long abs(long long x){
	if (x < 0) return -x;
	else return x;
}

int main(){
	long long a, b;
	cin >> a >> b;
	if (b > 0) cout << abs(a) << endl;
	else cout << -1*abs(a) << endl;
	return 0;
}