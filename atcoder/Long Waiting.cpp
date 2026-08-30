#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[300005], b[300005], c[300005];
struct node{
	long long t, c;
	friend bool operator < (const node x, const node y){
		return x.t > y.t;
	}
};
priority_queue<node> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	long long nc = 0, nt = 0;
	for (int i = 1; i <= n; i++){
		while (nc + c[i] > k){
			nt = q.top().t;
			nc -= q.top().c;
			q.pop(); 
		}
		nt = max(nt, 1ll * a[i]);
		nc += c[i];
		q.push({nt + b[i], c[i]});
		cout << nt << '\n';
	}
	return 0;
}

