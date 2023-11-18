#include <iostream>
#include <cmath>
using namespace std;

string s;
int a[4];

int main(){
	cin >> s;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 8; j++){
			a[i] += int(s[i*8+j]-'0') * pow(2, 7-j);
		}
	}
	cout << a[0] << '.' << a[1] << '.' << a[2] << '.' << a[3] << endl;
	return 0;
}