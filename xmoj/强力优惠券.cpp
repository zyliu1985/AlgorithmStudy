#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		q.push(a);
	}
	for (int i = 1; i <= m; i++){
		int x = q.top();
		q.pop();
		q.push(x / 2);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		ans += q.top();
		q.pop();
	}
	cout << ans << '\n';
	return 0;
}

