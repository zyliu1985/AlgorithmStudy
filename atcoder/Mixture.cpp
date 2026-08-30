#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool f[1 << 18], s[1 << 18];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i < 1 << n; i++){
			char c;
			cin >> c;
			s[i] = c - '0';
		}
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 1; i < 1 << n; i++){
			if (s[i]) continue;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1) f[i] |= f[i - (1 << j)];
		}
		if (f[(1 << n) - 1]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}



