#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int t[300005], c[300005];
int st[300005], sc[300005];
long long f[300005];
struct node{
	long long k;
	long long b;
};
deque<node> q;
node gt_ln(node x, node y){
	if (x.k == y.k) return {0, max(x.b, y.b)};
	long long rek = (x.b - y.b) / (x.k - y.k);
	long long reb = x.b - rek * x.k;
	return {rek, reb};
}
long long calc(node x, int p){
	return -x.k * p + x.b;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> c[i];
	for (int i = n; i >= 1; i--){
		st[i] = st[i+1] + t[i];
		sc[i] = sc[i+1] + c[i];
	}
	f[0] = 0;
	q.push_back(node{sc[1], sc[1] * 1ll * st[1]});
	for (int i = 1; i <= n; i++){
		long long x = st[i+1] - s;
		node now, nxt;
//		while (q.size() > 1){
//			now = q.front();
//			q.pop_front();
//			nxt = q.front();
//			if (-now.k * x + now.b <= -nxt.k * x + nxt.b){
//				q.push_front(now);
//				break;
//			}
//		}
		// Èý·Ö 
		int l = 0, r = q.size()-1;
		while (l < r){
			int mid1 = l + (r - l) / 3;
			int mid2 = l + ((r - l) * 2 + 2) / 3;
			if (calc(q[mid1], x) > calc(q[mid2], x)){
				l = mid1+1;
			} else if (calc(q[mid1], x) < calc(q[mid2], x)){
				r = mid2-1;
			} else {
				l = mid1+1;
				r = mid2;
			}
		}
		now = q[l];
		f[i] = -now.k * x + now.b;
//		for (int i = 0; i < q.size(); i++)
//			cout << q[i].k << ' ' << q[i].b << '\n';
//		cout << "------\n";
//		cout << q[l].k << ' ' << q[l].b << '\n';
//		cout << i << "--" << f[i] << '\n';
		long long nk = sc[i+1];
		long long nb = f[i] + sc[i+1] * 1ll * st[i+1];
		node awa = node{nk, nb};
		while (q.size() > 1){
			now = q.back();
			q.pop_back();
			nxt = q.back();
			node line = gt_ln(awa, nxt);
			if (now.b < line.k * now.k + line.b){
				q.push_back(now);
				break;
			}
		}
		q.push_back(awa);
	}
//	cout << f[5] << '\n';
	cout << f[n] << '\n';
	return 0;
}

