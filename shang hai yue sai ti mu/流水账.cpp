#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int minn = 1e9, now = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		now += x;
		minn = min(minn, now);
	}
	cout << -minn << endl;
}