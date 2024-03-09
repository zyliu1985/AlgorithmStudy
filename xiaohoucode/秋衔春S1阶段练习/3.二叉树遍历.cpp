#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node{
	string lc, rc;
} tr[40];
string s, t;
int cur;
queue<string> q;
map<string, int> mp;
void bfs(){
	q.push(s);
	while (!q.empty()){
		string x = q.front();
		char r = t[cur++];
		// cout << x << ' ' << r << endl;
		mp[x] = r-'A'+1;
		q.pop();
		int root;
		for (int i = 0; i < s.size(); i++)
			if (x[i] == r){
				root = i;
				break;
			}
		if (root != 0){
			q.push(x.substr(0, root));
			tr[r-'A'+1].lc = x.substr(0, root);
		}
		if (root != x.size()-1){
			q.push(x.substr(root+1));
			tr[r-'A'+1].rc = x.substr(root+1);
		}
	}
}
void dfs(int now){
	cout << char(now-1+'A');
	if (tr[now].lc != "") dfs(mp[tr[now].lc]);
	if (tr[now].rc != "") dfs(mp[tr[now].rc]);
}
int main(){
	cin >> s >> t;
	bfs();
	dfs(t[0]-'A'+1);
	return 0;
}