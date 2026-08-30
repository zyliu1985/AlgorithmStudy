#include <iostream>
#include <algorithm>
using namespace std;

int s[200005], r[200005], b[200005], cntr, cntb;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cntr = cntb = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		for (int i = 1; i <= n; i++){
			char c;
			cin >> c;
			if (c == 'R') r[++cntr] = s[i];
			else b[++cntb] = s[i];
		}
		sort(r+1, r+cntr+1, cmp);
		sort(b+1, b+cntb+1, cmp);
		long long ans = 0;
		for (int i = 1; i <= min(cntr, cntb); i++)
			ans += r[i] + b[i];
		if (cntb < cntr) ans += r[cntb+1];
		cout << ans << '\n';
	}
	return 0;
}



