#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("rank.in", "r", stdin);
	freopen("rank.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, a, s;
	cin >> n >> a >> s;
	if (a == 100){
		cout << "1 1\n";
	} else {
		cout << max(0, (s - n * a + 99 - a)) / (100 - a) + 1 << ' ' << min(n, (s - a) / (a + 1) + 1) << '\n';
	}
	return 0;
}

