#include <iostream>
using namespace std;

int ans;
int n, m;
int dict[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void dfs(int sum, int step){
	if (sum == 0){
		ans++;
		return;
	}
	if (step >= m) return;
	for (int i = (step == 0); i <= 9; i++)
		if (sum >= dict[i]) dfs(sum-dict[i], step+1);
}
int main(){
	cin >> n >> m;
	if (n == 6) ans++;
	dfs(n, 0);
	cout << ans << endl;
	return 0;
}