//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int mod = 1e9 + 7;
//long long hash2[1000005]; 
//long long pow26[10005];
//int main(){
//	ios::sync_with_stdio(0);
//    cin.tie(0);
//    pow26[0] = 1;
//    for (int i = 1; i <= 1e4; i++)
//    	pow26[i] = (pow26[i-1] * 26) % mod;
//	int t;
//	cin >> t;
//	while (t--){
//		int ans = 0;
//		string s1, s2;
//		cin >> s1 >> s2;
//		long long hash1 = 0;
//		for (int i = 1; i <= s1.size(); i++) 
//			hash1 = ((hash1 * 26) % mod + s1[i-1]) % mod;
//		for (int i = 1; i <= s2.size(); i++) 
//			hash2[i] = ((hash2[i-1] * 26) % mod + s2[i-1]) % mod;
//		for (int i = 1; i <= s2.size() - s1.size() + 1; i++)
//			ans += (hash1 == (hash2[i + s1.size() - 1] - (hash2[i-1] * pow26[s1.size()]) % mod + mod) % mod);
//		cout << ans << '\n';
//	}
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int _next[10005];
void build_next(string s){
	memset(_next, 0, sizeof(_next));
	_next[0] = 0;
	for (int i = 1; i < s.size(); i++)
		if (s[_next[i-1]] == s[i])
			_next[i] = _next[i-1] + 1;
		else{
			int now = _next[i-1];
			while (now){
				now = _next[now-1];
				if (s[now] == s[i]) _next[i] = now + 1;
			}
		}
			
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		build_next(s1);
//		for (int i = 0; i < s1.size(); i++)
//			cout << _next[i] << ' ';
		int i = 0, j = 0;
		while (i < s2.size()){
			if (s2[i] == s1[j]){
				if (j == s1.size() - 1) ans++, ;
				continue;
			}
		}
	}
	return 0;
}



