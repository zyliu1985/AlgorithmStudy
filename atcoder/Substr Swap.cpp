#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool nxt[2][500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 1; i <= n; i++)
		nxt[0][i] = 0, nxt[1][i] = 1;
	while (m--){
		int l, r;
		cin >> l >> r;
		nxt[0][l-1] ^= 1;
		nxt[0][r] ^= 1;
		nxt[1][l-1] ^= 1;
		nxt[1][r] ^= 1;
	}
	bool now = nxt[0][0];
	for (int i = 1; i <= n; i++){
		if (now){
			cout << t[i-1];
		} else {
			cout << s[i-1];
		}
		now = nxt[now][i];
	}
	return 0;
}

