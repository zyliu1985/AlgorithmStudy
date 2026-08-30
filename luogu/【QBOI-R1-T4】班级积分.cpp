#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[200005], ch[2][600005], L[600005], R[600005];
long long sum[600005], maxa[3][600005], lz[600005], cur = 1;
vector<int> t;
int n, m;
bool cmp(int x, int y){
	return x > y;
}
void push_up(int x){
	sum[x] = sum[ch[0][x]] + sum[ch[1][x]] + lz[x];
	t.clear();
	for (int i = 0; i < 3; i++) t.push_back(maxa[i][ch[0][x]]); 
	for (int i = 0; i < 3; i++) t.push_back(maxa[i][ch[1][x]]);
	sort(t.begin(), t.end(), cmp);
	for (int i = 0; i < 3; i++) maxa[i][x] = t[i]; 
}
void push_down(int x){
	for (int i = 0; i < 2; i++){
		sum[ch[i][x]] += lz[x];
		lz[ch[i][x]] += lz[x];
		for (int j = 0; j < 3; j++)
			maxa[j][ch[i][x]] += lz[x];
	}
	lz[x] = 0;
}
void build(int l = 1, int r = n, int x = 1){
	L[x] = l, R[x] = r;
	if (l == r){
		sum[x] = a[l], maxa[0][x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	ch[0][x] = ++cur;
	build(l, mid, cur);
	ch[1][x] = ++cur;
	build(mid+1, r, cur); 
	push_up(x);
}
void add(int l, int r, long long c, int x = 1){
	if (l <= L[x] && R[x] <= r){
		sum[x] += c * (R[x] - L[x] + 1);
		for (int i = 0; i < 3; i++)
			maxa[i][x] += c;
		lz[x] += c;
		return;
	}
	if (R[x] < l || r < L[x]) return;
	add(l, r, c, ch[0][x]);
	add(l, r, c, ch[1][x]);
	push_up(x);
}
long long quary(int l, int r, int x = 1){
	if (l <= L[x] && R[x] <= r) return sum[x];
	if (R[x] < l || r < L[x]) return 0;
	push_down(x);
	long long re = 0;
	re += quary(l, r, ch[0][x]);
	re += quary(l, r, ch[1][x]);
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	while (m--){
//		for (int i = 1; i <= cur; i++)
//			cout << "L:" << L[i] << ", R:" << R[i] << ", sum:" << sum[i] << ", max:" << maxa[0][i] << ' ' << maxa[1][i] << ' ' << maxa[2][i] << '\n';
//		cout << "-----------------------\n"; 
		int op;
		cin >> op;
		if (op == 1){
			int l, r, c;
			cin >> l >> r >> c;
			add(l, r, c);
		} else if (op == 2){
			int l, r;
			cin >> l >> r;
			cout << quary(l, r) << '\n';
		} else {
			cout << maxa[0][1] << ' ' << maxa[1][1] << ' ' << maxa[2][1]  << '\n';
		}
	}
	return 0;
}
