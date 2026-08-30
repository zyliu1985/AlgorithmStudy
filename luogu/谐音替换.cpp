#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int cur[2];
int ans, s[5000005];
int len[200005];
int ch[2][5000005][26], fail[2][5000005];
vector<int> ed[2][5000005];
bool vis[2][5000005];
queue<int> q;
map<pair<int, int>, bool> mp;
void build(bool id){
	q.push(0);
	vis[id][0] = true;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
			if (ch[id][x][i]){
				q.push(ch[id][x][i]);
				vis[id][ch[id][x][i]] = true;
				int now = fail[id][x];
				while (!ch[id][now][i] && now != 0){
//					cout << now << '\n';
					now = fail[id][now];
				}
				if (ch[id][now][i] && x != 0){
					fail[id][ch[id][x][i]] = ch[id][now][i];
				} else {
					fail[id][ch[id][x][i]] = 0;
				}
			} else {
				ch[id][x][i] = ch[id][fail[id][x]][i];
			} 
	}
}
void insert(string s, bool id, int cnt){
	int now = 0;
	for (int i = 0; i < s.size(); i++){
		if (!ch[id][now][s[i] - 'a']){
			cur[id]++;
			ch[id][now][s[i] - 'a'] = cur[id];
		}
		now = ch[id][now][s[i] - 'a'];
	} 
	ed[id][now].push_back(cnt);
} 
void quary(string t, bool id){
	int now = 0;
	for (int i = 0; i < t.size(); i++){
		cout << now <<'\n';
		now = ch[id][now][t[i] - 'a'];
		int qu = now;
		while (ed[id][qu].size() > 0){
			for (int j = 0; j < ed[id][qu].size(); j++){
				cout << ed[id][qu][j] << ',' << i << '\n';
				if (id){
					if (mp[{ed[id][qu][j], i}] && s[i - len[ed[id][qu][j]] + 1] == 0 && s[t.size()] == s[i + 1])
						ans++;
				} else mp[{ed[id][qu][j], i}] = true;
			}
			qu = fail[id][qu];
		}
//		for (int j = 0; j < ed[id][fail[id][now]].size(); j++){
//			cout << ed[id][fail[id][now]][j] << ',' << i << '\n';
//			if (id){
//				if (mp[{ed[id][fail[id][now]][j], i}] && s[i - len[ed[id][fail[id][now]][j]] + 1] == 0 && s[t.size()] == s[i + 1])
//					ans++;
//			} else mp[{ed[id][fail[id][now]][j], i}] = true;
//		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		len[i] = s1.size();
		insert(s1, 0, i), insert(s2, 1, i);
	} 
//	for (int i = 0; i <= cur[0]; i++){
//		for (int j = 0; j < 26; j++)
//			cout << ch[0][i][j] << ' ';
//		cout <<'\n';
//	}
//	cout << '\n';
	build(0);
	build(1);
	for (int i = 0; i <= cur[0]; i++)
		cout << fail[0][i] << ' ';
	cout << '\n';
//	for (int i = 0; i <= cur[0]; i++){
//		for (int j = 0; j < 26; j++)
//			cout << ch[0][i][j] << ' ';
//		cout <<'\n';
//	}
//	cout << '\n';
	while (q--){
		
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()){
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= t1.size(); i++)
			s[i] = s[i-1] + (t1[i-1] != t2[i-1]);
//		for (int i = 1; i <= t1.size(); i++)
//			cout << s[i] << ' ';
//		cout << '\n';
		quary(t1, 0), quary(t2, 1);
		cout << ans << '\n';
	}
	return 0;
}

