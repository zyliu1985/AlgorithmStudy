#include <iostream>
using namespace std;

int main(){
	string a, b;
	int ans = 1;
	cin >> a >> b;
	for (int i = 0; i < a.size()-1; i++){
		int x = b.find(a[i]);
		int y = b.find(a[i+1]);
		if (x-1 == y) ans *= 2;
	}
	cout << ans << endl;
}