#include <iostream>
#include <algorithm>
using namespace std;

bool now[500005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, q;
	cin >> n >> q;
	int ans = 0; 
	while (q--){
		int a;
		cin >> a;
		if (now[a]){
			if (now[a-1] && now[a+1]) ans++;
			else if (!now[a-1] && !now[a+1]) ans--;
		} else {
			if (now[a-1] && now[a+1]) ans--;
			else if (!now[a-1] && !now[a+1]) ans++;
		}
		now[a] ^= 1;
		cout << ans << '\n';
	}
	return 0;
}



