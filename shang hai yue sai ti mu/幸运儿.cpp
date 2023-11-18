#include <iostream>
using namespace std;

int main(){
	int n, x, m;
	cin >> n >> x >> m;
	int ans = (x+m-1)%n;
	if (ans == 0) ans - n;
	cout << ans << endl;
	return 0;
}