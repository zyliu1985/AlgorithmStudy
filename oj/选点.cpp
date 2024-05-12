#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

struct node{
	int a, b;
} e[100005];
int n, m;
bool cmp(node x, node y){
	return x.a < y.a;
}
bool check(int x){
	int i = 1, t = n, cur = e[1].a;
	while (i <= m && t > 0){
		cur = max(cur, e[i].a);
		int s = (e[i].b-cur+1) / x;
		s += ((e[i].b-cur+1) % x > 0);
		t -= s;
		cur += s * x;
		i++;
//		cout << i << ' ' << t << ' ' << cur << endl;
	}
//	cout << "--------------" << endl;
	return t < 1;
}
signed main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> e[i].a >> e[i].b;
	sort(e+1, e+m+1, cmp);
	int l = 0, r = 1e18;
	while (l < r){
		int mid = (l + r) / 2 + 1;
//		cout << mid << endl;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}