#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	long long a, b;
} x[105]; 
bool cmp(node x, node y){
	return x.a < y.a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k, s;
		cin >> n >> k >> s;
		for (int i = 1; i <= n; i++)
			cin >> x[i].a >> x[i].b;
		sort(x+1, x+n+1, cmp);
		int now = 1;
		long long ans = s;
		while (k > 0 || (now <= n && ans >= x[now].a)){
			while (now <= n && x[now].a <= ans) 
				ans = ans + x[now].b, now++;
			if (k > 0){
				ans *= 2;
				k--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

