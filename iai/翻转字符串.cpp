#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int scur = 1;
string s;
int nxt[1500005];
stack<int> st;
// 0:∆’Õ®  1:sub 
vector<pair<int, bool> > sub[500005];
void build(int l, int r, int id){
	if (r < 0) exit(0);
//	cout << l << ',' << r << ',' << id << '\n';
	for (int i = l; i <= r; i++)
		if (s[i] == '('){
			scur++;
			sub[id].push_back(make_pair(scur, 1));
			build(i+1, nxt[i]-1, scur);
			i = nxt[i];
		} else {
//			cout << s[i] << ';' << id << '\n';
			sub[id].push_back(make_pair(s[i], 0));
		}
}
void rev(int x, bool flag){
	if (flag){
		for (int i = 0; i < sub[x].size() / 2; i++)
			swap(sub[x][i], sub[x][sub[x].size() - i - 1]);
	}
	for (int i = 0; i < sub[x].size(); i++)
		if (sub[x][i].second){
			rev(sub[x][i].first, flag^1);
		} else {
			cout << char(sub[x][i].first);
		}
}
int main(){
//	freopen("in.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	bool flag = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '('){
			flag = flag^1;
			st.push(i);
		} else if (s[i] == ')'){
			flag = flag^1;
			nxt[st.top()] = i;
			st.pop();
		} else if (flag){
			if ('a' <= s[i] && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
			else if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		}
//	if (!st.empty()) return 9;
//	for (int i = 0; i < s.size(); i++)
//		cout << nxt[i] << ' ';
//	cout << '\n';
	build(0, s.size() - 1, 1);
//	for (int i = 1; i <= scur; i++){
//		for (int j = 0; j < sub[i].size(); j++){
//			if (sub[i][j].second){
//				cout << sub[i][j].first;
//			} else {
//				cout << char(sub[i][j].first);
//			}
//		}
//		cout << '\n';
//	}
	rev(1, 0);
	return 0;
}

