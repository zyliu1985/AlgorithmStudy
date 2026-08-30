#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> mp;
string s[205], t[205];
bool mark[205]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= m; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++){
		if (mp[s[i]]){
			mark[mp[s[i]]] = 1;
			mark[i] = 1;
			mp[s[i]] = n+1;
		} else {
			mp[s[i]] = i;
		}
		for (int j = 1; j <= m; j++){
			if (s[i].size() < t[j].size()) continue;
			bool flag = false;
			for (int k = 0; k < s[i].size() - t[j].size() + 1; k++){
				flag = true;
				for (int l = 0; l < t[j].size(); l++)
					if (s[i][k + l] != t[j][l]){
						flag = false;
						break;
					} 
				if (flag) break;
			}
			if (flag){
				mark[i] = true;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += mark[i];
	cout << ans << '\n';
	return 0;
}

