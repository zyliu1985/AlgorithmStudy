#include <iostream>
#include <algorithm>
using namespace std;

int x[100005]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	long long m;
	int mins = 2e9;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int y;
		cin >> x[i] >> y; 
		mins = min(mins, x[i] + y);
	}
	sort(x+1, x+n+1);
	long long sum = 0;
	long long ans = m / mins * 2;
	for (int i = 1; i <= n; i++){
		sum += x[i];
		if (sum > m) break;
		ans = max(ans, (m - sum) / mins * 2 + i);
	}
	cout << ans << '\n';
	return 0;
}

