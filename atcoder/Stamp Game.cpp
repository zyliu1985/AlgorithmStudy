#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int a[1005][1005];
long long s[1005][1005];
long long maxa[1005][1005];
long long maxb[1005][1005];
long long calc(int x1, int y1, int x2, int y2){
	return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}
struct node{
	long long x, id;
};
deque<node> q;
void insert(node x){
	while (!q.empty() && x.x >= q.back().x) q.pop_back();
	q.push_back(x);
}
node query(int id, int len){
	while (!q.empty() && q.front().id > id + len - 1) q.pop_front();
	if (q.empty()) return node{-1, -1};
	return q.front();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, n1, m1, n2, m2;
	cin >> n >> m >> n1 >> m1 >> n2 >> m2;
	n2 = min(n2, n1);
	m2 = min(m2, m1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	for (int i = 1; i <= n - n2 + 1; i++){
		q.clear();
		for (int j = m - m2 + 1; j >= 1; j--){
			insert(node{calc(i, j, i+n2-1, j+m2-1), j});
			maxa[i][j] = query(j, m1-m2+1).x;
		}
	}
//	for (int i = 1; i <= n - n2 + 1; i++){
//		for (int j = 1; j <= m - m2 + 1; j++){
//			cout << maxa[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for (int j = 1; j <= m - m2 + 1; j++){
		q.clear();
		for (int i = n - n2 + 1; i >= 1; i--){
			insert(node{maxa[i][j], i});
			maxb[i][j] = query(i, n1-n2+1).x;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n - n1 + 1; i++)
		for (int j = 1; j <= m - m1 + 1; j++)
			ans = max(ans, calc(i, j, i+n1-1, j+m1-1) - maxb[i][j]);
	cout << ans << '\n';
	return 0;
}

