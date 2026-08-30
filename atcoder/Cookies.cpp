#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[55];
struct node{
	int num[55];
	long long val;
	friend bool operator < (const node x, const node y){
		return x.val < y.val;
	} 
};
priority_queue<node> q;
bool cmp(int a, int b){
	return a > b;
}
node t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k, x; 
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1, cmp);
	t.num[1] = k;
	t.val = k * 1ll * a[1];
	q.push(t);
	while (x--){
		node nx = q.top();
		q.pop();
		cout << nx.val << '\n';
		for (int i = 1; i < n; i++){
			if (nx.num[i] > 0){
				nx.num[i]--;
				nx.num[i+1]++;
				nx.val = nx.val - a[i] + a[i+1];
				q.push(nx);
				nx.num[i]++;
				nx.num[i+1]--;
				nx.val = nx.val + a[i] - a[i+1];
			}
		}
	}
	return 0;
}

