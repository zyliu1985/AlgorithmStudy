#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], b[200005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int j = 1; j <= m; j++)
		cin >> b[j];
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+m+1, cmp);
	long long ans = 0;
	int cnt; 
	for (cnt = 1; cnt <= min(n, m); cnt++) {
		if (b[cnt] > 0 && a[cnt] + b[cnt] > 0) ans += a[cnt] + b[cnt];
		else break;
	}
	while (a[cnt] > 0) ans += a[cnt++];
	cout << ans << '\n';
	return 0;
}



