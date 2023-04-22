#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string tt, ss;
map<string, vector<string>> mp;
map<string, bool> dir;
map<string, int> step;
map<string, string> ftr;
queue<string> q;

void bfs(){
	string x = q.front();
	if (x == ss) return;
	else if (q.empty()){
		step[ss] = -1;
		return;
	}
	for (int i = 0; i < mp[x].size(); i++){
		string cnt = mp[x][i];
		if (!dir[cnt]){
			q.push(cnt);
			dir[cnt] = true;
			step[cnt] = step[x]+1;
			ftr[cnt] = x;
		}
	}
	q.pop();
	bfs();
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		vector<string> v;
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++){
			string t;
			cin >> t;
			v.push_back(t);
		}
		mp[s] = v;
	}
	cin >> tt >> ss;
	if (!mp.count(tt)){
		cout << -1 << endl;
		return 0;
	}
	if (ss == tt){
		cout << 0 << endl << tt;
		return 0;
	}
	dir[tt] = true;
	step[tt] = 0;
	q.push(tt);
	bfs();
	cout << step[ss] << endl;
	if (step[ss] == -1){
		return 0;
	}
	string bf[105];
	string s = ss;
	int j = 1;
	while (s != tt){
		bf[j] = s;
		s = ftr[s];
		j++;
	}
	cout << tt;
	for (int i = step[ss]; i >= 1; i--){
		cout << "->" << bf[i];
	}
	return 0;
}