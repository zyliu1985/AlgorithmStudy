#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tre[205][150], cur;
bool ed[205];
void set_up(){
	cur = 0;
	memset(tre, 0, sizeof(tre));
	memset(ed, false, sizeof(ed));
}
void insert(string s){
	int now = 0;
	for (int i = 0; i < s.size(); i++){
		int t = s[i];
		if (!tre[now][t]) tre[now][t] = ++cur;
		now = tre[now][t];
	}
	ed[now] = true;
}
void find(string s){
	int now = 0;
	for (int i = 0; i < s.size(); i++){
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < s.size()/2; j++)
			swap(s[j], s[s.size()-j-1]);
		cout << s << '\n';
		insert(s);
	}
	
	return 0;
}

