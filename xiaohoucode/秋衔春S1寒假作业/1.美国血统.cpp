#include <iostream>
using namespace std;

void dfs(string mid, string front){
	if (mid.size() < 1) return;
	char root = front[0];
	string sm, sf, tm, tf;
	int i = 0;
	while (mid[i] != root){
		sm += mid[i];
		sf += front[i+1];
		i++;
	}
	i++;
	for ( ; i < mid.size(); i++){
		tm += mid[i];
		tf += front[i];
	}
	dfs(sm, sf);
	dfs(tm, tf);
	cout << root;
}
int main(){
	string s, t;
	cin >> s >> t;
	dfs(s, t);
	return 0;
}