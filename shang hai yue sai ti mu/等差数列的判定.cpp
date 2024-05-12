#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	bool ans = true;
	int a, cha, lasta;
	cin >> lasta >> a;
	cha = a - lasta;
	lasta = a;
	for (int i = 3; i <= n; i++){
		cin >> a;
		if (a - lasta != cha){
			ans = false;
			break;
		}
		lasta = a;
	}
	if (ans) cout << "Arithmetic Sequence" << endl;
	else cout << "No" << endl;
}