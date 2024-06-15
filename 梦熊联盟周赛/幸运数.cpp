#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long n;
	cin >> n;
	n++;
	string s;
	while (n > 1){
		if (n & 1) s = '7' + s;
		else s = '2' + s;
		n /= 2;
	}
	cout << s << endl;
	return 0;
}