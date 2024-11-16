#include <iostream>
#include <algorithm>
using namespace std;

int n, a[105];
long long m;
long long ans = 1e18;
void dfs(int step, int sum, int k){
	if (step > n){
		if (k != 0 && (m - sum) % k == 0){
			ans = min(ans, (m - sum) / k);
		}
		return;
	}
	dfs(step + 1, sum + a[step], k + 1);
	dfs(step + 1, sum, k);
} 
int main(){
	freopen("potion.in", "r", stdin);
	freopen("potion.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
