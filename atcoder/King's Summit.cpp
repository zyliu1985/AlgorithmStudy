#include <iostream>
#include <algorithm>
using namespace std;

int x[200005], y[200005], ox[200005], oy[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> ox[i] >> oy[i];
		x[i] = ox[i], y[i] = oy[i]; 
	}
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);
	int tarx = (x[1] + x[n]) / 2, tary = (y[1] + y[n]) / 2;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(abs(ox[i] - tarx), abs(oy[i] - tary)));
	cout << ans << '\n';
	return 0;
}

