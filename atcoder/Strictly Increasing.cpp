#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int last;
	cin >> last;
	for (int i = 2; i <= n; i++){
		int a;
		cin >> a;
		if (a <= last){
			cout << "No" << '\n';
			return 0;
		}
		last = a;
	}
	cout << "Yes\n";
	return 0;
}


