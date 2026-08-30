#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cur;
int tr[1000005][10];
bool flag[1000005];
void setup(){
	cur = 0;
	memset(tr, 0, sizeof(tr));
	memset(flag, 0, sizeof(flag));
}
bool insert(string s){
	int now = 0;
	bool fg = 0;
	for (int i = 0; i < s.size(); i++){
		if (flag[now]) return true;
		if (!tr[now][s[i] - '0']){
			cur++;
			tr[now][s[i] - '0'] = cur;
			now = cur; 
			fg = 1;
		} else {
			now = tr[now][s[i] - '0'];
		}
	}
	flag[now] = 1;
	return !fg;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	int t = 1;
	while (cin >> s){
		setup();
		bool ans = 0;
		while (s != "9"){
			ans |= insert(s); 
			cin >> s;
		}
		if (ans) cout << "Set "<< t << " is not immediately decodable\n";
		else cout << "Set "<< t <<" is immediately decodable\n";
		t++;
	}
	return 0;
}

