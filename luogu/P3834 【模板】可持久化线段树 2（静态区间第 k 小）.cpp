#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int l, r, k;
	bool type;
} q[400005];
bool cmp(node x, node y){
	return x.r < y.r;
}
int cur;
void solve(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid), solve(mid+1, r);
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		q[++cur] = {i, i, x, 0};
	}
	for (int i = 1; i <= n; i++){
		int l, r, k;
		cin >> l >> r >> k;
		q[++cur] = {l, r, k, 1};
	}
	sort(q+1, q+cur+1, cmp);
	solve(1, cur);
	return 0;
}

