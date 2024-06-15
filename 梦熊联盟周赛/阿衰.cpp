#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005], cur, sum, ed;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n+1] = 1e9;
	ed = n;
	sort(a+1, a+n+1);
	cur = 1;
	for (int i = 1; i <= 2*1e6; i++){
		int d = a[cur] - i;
		cout << cur << ' ' << ed << ' ' << sum << ' ' << i << ' ' << d << endl;
		if (d < 0){
			sum++;
			cur++;
			i--;
		} else if (d == 0){
			sum++;
			cur++;
		} else if (sum >= 2) sum--;
		else if (sum == 1 && ed - cur >= 0) {
			a[ed] = 1e9;
			ed--;
		} else if (ed - cur >= 1){
			a[ed] = 1e9;
			a[ed-1] = 1e9; 
			ed -= 2;
			sum++;
		} else {
			cout << i-1 << endl;
			return 0;
		}
	}
	return 0;
}