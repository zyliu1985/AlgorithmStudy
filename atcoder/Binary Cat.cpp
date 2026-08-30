#include <iostream>
#include <algorithm>
using namespace std;

long long len[500005];
int l[500005], r[500005];
bool solve(int x, int q){
	if (x < 2) return x;
	if (x <= len[l[x]]) return solve(l[x])
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	len[0] = len[1] = 1;
	int q;
	cin >> q;
	for (int i = 2; i <= q + 1; i++){
		int x;
		cin >> l[i] >> r[i] >> x;
		len[i] = min(1000000000000000000, len[l[i]] + len[r[i]]);
		cout << solve(i, x) << '\n';
	}
	return 0;
}

