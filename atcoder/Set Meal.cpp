#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<int, int> mp;
struct node{
	int i, j;
} ans;
queue<node> q;
int a[100005], b[100005];
int n, m, l;
void bfs(){
	q.push({n, m});
	while (!q.empty()){
		int x, y;
		x = q.front().i;
		y = q.front().j;
		q.pop();
		if (mp[a[x]] != b[y] && a[x] + b[y] > a[ans.i] + b[ans.j]){
			cout << mp[a[x]] << '|' << b[y] << endl;
			ans.i = x;
			ans.j = y;
			cout << x << ',' << y << ' ' << a[x] + b[y] << endl;
			continue;
		}
		if (a[x-1] + b[y] > a[ans.i] + b[ans.j]) q.push({x-1, y});
		if (a[x] + b[y-1] > a[ans.i] + b[ans.j]) q.push({x, y-1});
	}
}
int main(){
	ans.i = ans.j = 0;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= l; i++){
		int x, y;
		cin >> x >> y;
		mp[a[x]] = b[y];
		cout << a[x] << ',' << b[y] << endl;
	}
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	bfs();
	cout << a[ans.i] + b[ans.j] << endl;
	return 0;
}