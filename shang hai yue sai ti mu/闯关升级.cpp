#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], b[100005];

int main(){
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	int tt = t;
	int cnt1 = 0, cnt2 = 0;
	while (t >= 0){
		cnt1++;
		t -= a[cnt1];
	}
	cnt1--;
	t = tt;
	while (t >= 0){
		cnt2++;
		t -= b[cnt2];
	}
	cnt2--;
	cout << max(cnt1, cnt2) << endl;
	return 0;
}