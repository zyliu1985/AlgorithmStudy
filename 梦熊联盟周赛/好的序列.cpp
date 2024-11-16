#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int w[100005], f[100005];
int main(){
	freopen("increase.in", "r", stdin);
	freopen("increase.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	int ans = 0;
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++){
		f[w[i]] = max(f[w[i]], f[w[i] - 1] + 1); 
		ans = max(ans, f[w[i] - 1] + 1);
	}
	cout << ans << endl;
	return 0;
}
