#include <iostream>
#include <algorithm>
using namespace std;

int f[205];
void solve(string s){
	int ans = 0;
	for (int i = 1; i <= s.size(); i++){
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (s[j] < s[i]) f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		string s, k;
		cin >> s >> k;
		if (k == "1"){
			solve("!"+s);
		} else {
			solve("!"+s+s);
		}
	}
	return 0;
}


