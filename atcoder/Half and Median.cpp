#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		while (!q.empty()) q.pop();
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			q.push(x);
		} 
		for (int i = 1; i <= m; i++){
			int x = q.top();
			q.pop();
			q.push(x / 2);
			q.push((x + 1) / 2);
		}
//		while (!q.empty()){
//			cout <<q.top() << ' ';
//			q.pop();
//		}
//		cout << '\n';
		if ((n + m) % 2 == 1){
			for (int i = 1; i <= (n + m) / 2; i++) q.pop();
			cout << q.top() << '\n';
		} else {
			for (int i = 1; i <= (n + m) / 2 - 1; i++) q.pop();
			double as = q.top();
			q.pop();
			as = (as + q.top()) / 2;
			cout << as << '\n';
		}
	}
	return 0;
}

