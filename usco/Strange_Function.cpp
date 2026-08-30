#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long func[200005], s[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	func[0] = 1;
	s[0] = 1;
	for (int i = 1; i <= 2e5; i++){
		func[i] = (s[i-1] + 2) % mod;
		s[i] = (s[i-1] + func[i]) % mod;
	}
	while (t--){
		string s;
		cin >> s;
		bool flag = 0;
		long long ans = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] != '0' && s[i] != '1') flag = 1;
			if ((s[i] - '0') & 1){
				ans += func[s.size() - i - 1];
			}
		}
		cout << (ans + flag) % mod << '\n';
	}
	return 0;
}

