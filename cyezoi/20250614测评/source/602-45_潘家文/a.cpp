#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
int n, b[5], c;
vi ans;

int main(){
	string t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int _ = 0; _ < n; ++ _){
		cin >> t;
		for(int i = 0; i < 5; ++ i) if(t[i] == 'Y') ++ b[i];
	}
	for(int i = 0; i < 5; ++ i){
		if(b[i] > c){
			c = b[i];
			ans.clear();
			ans.push_back(i + 1);
		}
		else if(b[i] == c) ans.push_back(i + 1);
	}
	for(int i = 0; i < ans.size() - 1; ++ i) cout << ans[i] << ',';
	cout << ans.back();
}

