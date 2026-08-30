#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, ans = 0;
	cin >> n; 
	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		if (b > a) ans++;
	} 
	cout << ans << '\n';
	return 0;
}



