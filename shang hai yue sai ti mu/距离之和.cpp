#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

struct node{
	int x, y;
} c[300005];
bool cmpx(node x, node y){
	return x.x < y.x;
}
bool cmpy(node x, node y){
	return x.y < y.y;
}
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i].x >> c[i].y;
	int ans = 0;
	sort(c+1, c+n+1, cmpx);
	for (int i = 1; i <= n-1; i++)
		ans += (c[i+1].x - c[i].x) * i * (n - i);
	sort(c+1, c+n+1, cmpy);
	for (int i = 1; i <= n-1; i++)
		ans += (c[i+1].y - c[i].y) * i * (n - i);
	cout << ans << endl;
	return 0;
}