#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct node{
	int val, id;
	friend bool operator < (const node x, const node y){
		if (x.val != y.val) return x.val < y.val;
		return x.id < y.id;
	}
} a[1000005];
deque<node> q1, q2;
int main(){
//	freopen("snakes4.in", "r", stdin); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	bool flag = true;
	int n;
	while (t--){
		q1.clear();
		q2.clear();
		int k;
		cin >> k;
		if (flag){
			n = k;
			for (int i = 1; i <= n; i++){
				cin >> a[i].val;
				a[i].id = i;
			}
			flag = false;
		} else {
			for (int i = 1; i <= k; i++){
				int x, c;
				cin >> x >> c;
				a[x].val = c;
			}
		}
		for (int i = 1; i <= n; i++)
			q1.push_back(a[i]);
		bool flag2 = false;
		while (q1.size() + q2.size() > 1){
			node y;
			if (q1.empty()){
				// 上一个进来的成为了我吃的人，不行 
				flag2 = true;
				break;
			} else if (q2.empty()) y = q1.front(), q1.pop_front();
			else if (q1.front() < q2.front()) y = q1.front(), q1.pop_front();
			else{
				// 上一个进来的成为了我吃的人，不行 
				flag2 = true;
				break;
			}
			node x;
			if (q1.empty()) x = q2.back(), q2.pop_back();
			else if (q2.empty()) x = q1.back(), q1.pop_back();
			else if (q1.back() < q2.back()) x = q2.back(), q2.pop_back();
			else x = q1.back(), q1.pop_back();
			node z = {x.val - y.val, x.id};
			q2.push_front(z);
		}
		int ans = q1.size() + q2.size();
//		cout << ans << ' ' << flag2 << '\n'; 
		if (flag2){
//			for (int i = 0; i < q1.size(); i++)
//				cout << q1[i].val << ',';
//			cout << "\n\n";
//			for (int i = 0; i < q2.size(); i++)
//				cout << q2[i].val << ',';
//			cout << '\n'; 
			bool eat = 0;
			while (q1.size() + q2.size() > 1){
				node y;
				if (q1.empty()) y = q2.front(), q2.pop_front();
				else if (q2.empty()){
					// 放心吃了
//					cout << "empty\n";
					break; 
				} else if (q1.front() < q2.front()){
					// 放心吃了
//					cout << "smaller\n";
					break; 
				} else y = q2.front(), q2.pop_front();
				node x;
				if (q1.empty()) x = q2.back(), q2.pop_back();
				else if (q2.empty()) x = q1.back(), q1.pop_back();
				else if (q1.back() < q2.back()) x = q2.back(), q2.pop_back();
				else x = q1.back(), q1.pop_back();
//				cout << "(" << y.val << ", " << x.val << ") = " << x.val - y.val << '\n';
				node z = {x.val - y.val, x.id};
				eat ^= 1;
				if (!q2.empty() && q2.front() < z) break;
				q2.push_front(z);
			}
//			cout << eat << '\n';
			cout << ans + eat << '\n';
		} else cout << q1.size() + q2.size() << '\n';
	}
	return 0;
}

