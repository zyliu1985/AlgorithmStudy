#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int s, id;
} a[200005];
bool cmp(node x, node y){
	return x.s < y.s;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].s, a[i].id = i;
		sort(a+1, a+n+1, cmp);
		int st, ed, ans = 1, last;
		for (int i = 1; i <= n; i++)
			if (a[i].id == 1) st = i, last = i;
			else if (a[i].id == n) ed = i;
		bool flag = false;
		while (st < ed){
			ans++;
			st = upper_bound(a+1, a+n+1, node{a[st].s * 2, 0}, cmp) - a - 1;
			if (st == last){
				cout << -1 << '\n';
				flag = true;
				break;
			}
			last = st;
		}
		if (flag) continue;
		cout << max(ans, 2) << '\n';
	}
	return 0;
}



