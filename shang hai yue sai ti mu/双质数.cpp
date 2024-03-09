#include <iostream>
#include <cmath>
using namespace std;

bool fun(int x){
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++){
		if (x % i == 0) return false;
	}
	return true;
}
int main(){
	int a, b;
	cin >> a >> b;
	bool flag = true;
	for (int i = a; i <= b; i++){
		if (fun(i) && fun(i/10)){
			flag = false;
			cout << i << endl;
		}
	}
	if (flag) cout << "None" << endl;
	return 0;
}