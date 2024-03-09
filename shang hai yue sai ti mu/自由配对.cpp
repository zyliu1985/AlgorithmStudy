#include <iostream>
using namespace std;

int a[1000005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[a[i]] == i) cnt++;
	}
	cout << cnt/2 << endl;
	return 0;
}