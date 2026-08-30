#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct node{
	int x, y;
} t[200005];
struct node1{
	int x, y;
	friend bool operator < (const node1 x, const node1 y){
		return x.x < y.x;
	}
};
struct node2{
	int x, y;
	friend bool operator < (const node2 x, const node2 y){
		return x.y < y.y;
	}
};
bool cmp(node x, node y){
	return x.x - x.y < y.x - y.y;
}
set<node1> a;
set<node2> b;
set<int> ac, bc;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n ;
	for (int i = 1; i <= n; i++)
		cin >> t[i].x >> t[i].y;
	sort(t+1, t+n+1, cmp);
	a.insert({-1, -1});
	b.insert({-1, -1});
	a.insert({2e9, 2e9});
	b.insert({2e9, 2e9});
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (ac.find(t[i].x) != ac.end() || bc.find(t[i].y) != bc.end()) continue;
		node1 ra = *a.lower_bound({t[i].x, t[i].y});
		node2 rb = *b.lower_bound({t[i].x, t[i].y});
		if (ra.x == rb.x && ra.y == rb.y){
			ac.insert(t[i].x);
			bc.insert(t[i].y);
			a.insert({t[i].x, t[i].y});
			b.insert({t[i].x, t[i].y});
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

