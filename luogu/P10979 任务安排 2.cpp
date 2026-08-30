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
		while (q.size() > 1){
			now = q.front();
			q.pop_front();
			nxt = q.front();
			if (-now.k * x + now.b <= -nxt.k * x + nxt.b){
				q.push_front(now);
				break;
			}
		}
		cout <<  q.front().k << ' ' << q.front().b << '\n';
		now = q.front();
		f[i] = -now.k * x + now.b;
		cout << i << "--" << f[i] << '\n';
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

