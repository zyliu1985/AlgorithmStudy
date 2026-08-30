#include <iostream>
#include <algorithm>
using namespace std;

int n;
unsigned long long t;
unsigned long long b[105];
bool a[105];
void dfs(int x, unsigned long long sum){
	if (sum > t) return;
	if (x > n){
		if (sum == t){
			for (int i = 1; i <= n; i++)
				cout << a[i];
			exit(0);
		}
		return;
	}
	a[x] = 0;
	dfs(x+1, sum);
	a[x] = 1;
	dfs(x+1, sum+b[x]);
}
int main(){
	freopen("Ne.in", "r", stdin);
	freopen("Ne.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	cin >> t;
	dfs(1, 0);
	return 0;
}

