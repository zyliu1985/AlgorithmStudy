#include <iostream>
#include <algorithm>
using namespace std;

int nxt[10000005];
void build_next(string s){
	nxt[0] = 0;
	int l = 0;
	for (int r = 1; r < s.size(); r++){
		while (s[l] != s[r] && l != 0) l = nxt[l-1];
		if (s[l] != s[r]){
			nxt[r] = 0;	
			continue;
		} else nxt[r] = l+1;
		l++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	while (s != "."){
		int n = s.size();
		build_next(s);
		if (n % (n - nxt[n-1]) > 0) cout << 1 << '\n';
		else cout << n / (n - nxt[n-1]) << '\n';
		cin >> s; 
	}
	return 0;
}

