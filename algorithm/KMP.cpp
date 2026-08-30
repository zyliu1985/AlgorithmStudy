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
int kmp(string s, string t){
	int re = 0;
	build_next(t);
	int j = 0;
	for (int i = 0; i < s.size(); i++){
		while (s[i] != t[j] && j != 0) j = nxt[j-1];
		if (s[i] != t[j]) continue;
		j++;
		if (j == t.size()){
			re++;
			j = nxt[j-1];
			continue;
		}
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	return 0;
}

