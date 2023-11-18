#include <iostream>
using namespace std;

int a[300005], ans, n, m;
const int mod = 1000000007;

void f(int last, int end, int d){
	ans += (last/end)*a[d];
	ans %= mod;
	cout << ans << ' '<<last/end<<' '<<a[d]<< endl;
	if (d == 0) return;
	f(last/end, end-1, d-1);
}

int main(){
	int last = 1;
	cin >> n >> m;
	for (int i = 0; i <= n; i++){
		cin >> a[i];
	}
	for (int i = m; i >= m-n+1; i--){
		last *= i;
	}
	ans += last*a[n];
	cout << a[n] << endl;
	f(last, m-n+1, n-1);
	cout << ans << endl;
	return 0;
}