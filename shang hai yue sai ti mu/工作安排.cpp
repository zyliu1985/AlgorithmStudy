#include <iostream>
#include <algorithm>
using namespace std;

struct work{
	int t, f;
} a[200005];
bool cmp(work x, work y){
	return x.t < y.t;
}

int main(){
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].t >> a[i].f;
	}
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			ans += a[j].f * a[i].t;
		}
	}
	cout << ans << endl;
	return 0;
}