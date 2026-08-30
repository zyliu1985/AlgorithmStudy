#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct node{
	int x, y;
} a[2005];
bool cmp(node x, node y){
	if (x.x != y.x) return x.x < y.x;
	return x.y > y.y;
}
map<double, int> mp;
map<pair<double, long long>, int> mp2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++){
			mp[(a[j].y - a[i].y) * 1.0 / (a[j].x - a[i].x)]++;
			pair<double, long long> p((a[j].y - a[i].y) * 1.0 / (a[j].x - a[i].x), (a[j].y - a[i].y) * (a[j].y - a[i].y) + (a[j].x - a[i].x) * (a[j].x - a[i].x));
			mp2[p]++;
		}
	double ans = 0;
	for (auto kv : mp){
//		cout << kv.first << ' ' << kv.second << '\n';
		ans += kv.second * (kv.second - 1) / 2;
	}
	for (auto kv : mp2){
		ans -= kv.second * (kv.second - 1) * 1.0 / 4;
	}
	cout << int(ans) << '\n';
	return 0;
}

