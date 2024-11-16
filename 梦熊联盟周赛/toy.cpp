#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[200005];
bool check(int mid){
	int x = upper_bound(a+1, a+n+1, a[1] + mid * 2) - a;
//	cout << "mid x: " << x << endl;
	int y = upper_bound(a+1, a+n+1, a[x] + mid * 2) - a;
//	cout << "mid y: " << y << endl;
	int z = upper_bound(a+1, a+n+1, a[y] + mid * 2) - a;
//	cout << "mid z: " << z << endl;
	return z > n;
}
int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	a[n+1] = a[n];
	int l = 0, r = a[n] - a[1] + 1;
	while (l < r){
		int mid = (l + r) / 2;
//		cout << mid << endl;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
