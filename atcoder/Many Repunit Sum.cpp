#include <iostream>
#include <algorithm>
using namespace std;

int a[200020];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[x-1]++;
	}
	for (int i = 2e5; i >= 0; i--){
		a[i] += a[i+1];
	}
	for (int i = 0; a[i] != 0 || i <= 2e5; i++){
		if (a[i] >= 10){
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	bool lead = 0;
	for (int i = 2e5+10; i >= 0; i--){
		if (lead) cout << a[i];
		else if (a[i] != 0) lead = 1, cout << a[i];
	}
	return 0;
}

