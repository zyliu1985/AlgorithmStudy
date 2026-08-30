#include <iostream>
#include <algorithm>
#include <random> 
using namespace std;

mt19937 mt(114514);
int w[500005];
long long org[500005];
long long rd[500005];
long long sum1, sum2;
int main(){
//	freopen(""); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		w[i] = mt() % 300000 + 100000;
		sum1 += w[i];
	}
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		rd[b] += w[a];
		org[b] += w[a];
	}
	for (int i = 1; i <= n; i++)
		sum2 += rd[i];
	int q;
	cin >> q;
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int a, b;
			cin >> a >> b;
			sum2 -= w[a];
			rd[b] -= w[a];
		} else if (op == 2){
			int x;
			cin >> x;
			sum2 -= rd[x];
			rd[x] = 0;
		} else if (op == 3){
			int a, b;
			cin >> a >> b;
			sum2 += w[a];
			rd[b] += w[a];
		} else {
			int x;
			cin >> x;
			sum2 += org[x] - rd[x];
			rd[x] = org[x];
		}
		if (sum1 == sum2){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

