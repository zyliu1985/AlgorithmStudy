#include <iostream>
#include <algorithm>
using namespace std;

int cur;
bool bit[35];
struct edge{
	int u, v;
} e[10005];
int n, m;
int main(){
//	freopen("path.in", "r", stdin);
//	freopen("path.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	if (k == 0){
		cout << "2 0\n";
		return 0;
	}
	if (k == 1) cout << "1 0\n";
	while (k){
		bit[++cur] = k & 1;
		k >>= 1;
	}
	n = 3;
	e[++m] = {1, 2};
	e[++m] = {1, 3};
	if (bit[cur-1]){
		e[++m] = {n-1, n};
	}
	for (int i = cur - 2; i >= 1; i--){
		e[++m] = {n-1, n+1};
		e[++m] = {n-1, n+2};
		e[++m] = {n, n+1};
		e[++m] = {n, n+2};
		n += 2;
		if (bit[i]){
			e[++m] = {1, n};
		}
	}
	e[++m] = {n-1, n+1};
	e[++m] = {n, n+1};
	n++;
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= m; i++)
		cout << e[i].u << ' ' << e[i].v << '\n'; 
	return 0;
}

