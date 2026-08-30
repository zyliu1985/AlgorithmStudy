#include <iostream>
#include <algorithm>
using namespace std;

int p[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	if (p[n] != n){
		cout << "-1\n";
		return 0;
	}
	int ans = 0, lst;
	for (int i = n; i >= 1; ){
		lst = p[i];
		while (p[i] >= lst) i--;
		ans += lst - p[i] - 1;
	}
	cout << ans << '\n';
	return 0;
}

