#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int a, b;
} a[100005];
bool cmp(node x, node y){
	return x.b < y.b;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].b;
	sort(a+1, a+n+1, cmp);
	int l = 1, r = n, ans = 0;
	while (l < r){
		ans = max(ans, a[l].b + a[r].b);
		if (a[l].a > a[r].a){
			r--;
			a[l].a -= a[r].a;
		} else if (a[l].a < a[r].a){
			l++;
			a[r].a -= a[l].a;
		} else {
			l++;
			r--;
		}
	}
	if (l == r) ans = max(ans, a[l].b * 2);
	cout << ans << endl;
	return 0;
}