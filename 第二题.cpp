#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string s;

int main(){
	long long n, len = 1;
	cin >> n;
	long long t = n;
	while (pow(2, len) < t){
		t -= pow(2, len);
		len++;
	}
	//cout << len << endl;
	for (int i = 1; i <= len; i++){
		int x = n % (long long)(pow(2, i));
		if (x <= pow(2, i)/2 && x != 0){
			s = '6' + s;
		} else {
			s = '8' + s;
		}
		n -= pow(2, i);
	}
	cout << s << endl;
	return 0;
}