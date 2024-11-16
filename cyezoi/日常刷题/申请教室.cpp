#include <iostream>
using namespace std;

int d[1000005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		d[l]++;
		d[r+1]--;
	}
	int ans = 0, sum = 0;
	for (int i = 1; i <= 1000000; i++){
		sum += d[i];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}