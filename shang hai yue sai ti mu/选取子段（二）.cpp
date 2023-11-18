#include <iostream>
using namespace std;

int a[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnt = 0, t = 0;
	for (int i = 1; i <= n; i++){
		t++;
		if (a[i+1] != a[i]) {
			cnt += (t+1) * t / 2;
//			cout << cnt << ' ' << t << endl;
//			cout << t << endl;
			t = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}