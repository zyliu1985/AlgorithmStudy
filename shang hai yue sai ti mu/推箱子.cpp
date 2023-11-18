#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int ans = 1e8;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == '@') cnt++;
		}
		for (int j = 0; j < s.size()-cnt; j++){
			int x = 0, y = 0;
			for (int k = 0; k < s.size(); k++){
				if (s[k] == '@'){
					x += abs(j+y-k);
					y++;
				}
			}
			ans = min(ans, x);
		}
		cout << ans << endl;
	}
	return 0;
}