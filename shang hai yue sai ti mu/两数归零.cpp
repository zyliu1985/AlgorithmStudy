#include <iostream>
using namespace std;

int a[300005];

int main(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (a[i] + a[j] == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}