#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int pri = 131;
unsigned long long gethash(string s){
	unsigned long long re = 0;
	for (int i = 0; i < s.size(); i++)
		re = re * pri + s[i];
	return re;
}
string rev(string s){
	if (s.size() == 0) return s;
	string t;
	for (int i = s.size()-1; i >= 0; i--)
		t += s[i];
	return t; 
}
int cur, cur2;
map<pair<unsigned long long, unsigned long long>, int> mp;
map<unsigned long long, int> qh;
int ans[200005];
int cnt[200005];
struct trie{
	struct qu{
		int val, id;
	};
	struct node{
		vector<qu> query;
		vector<int> qhash;
		int ch[26];
		node(){
			query.clear();
			qhash.clear();
			for (int i = 0; i < 26; i++)
				ch[i] = 0;
		}
	};
	vector<node> tr;
	trie(){
		node temp;
		tr.push_back(temp);
	}
	void insert(string p, int qhid){
		int now = 0;
		for (int i = 0; i < p.size(); i++){
			if (tr[now].ch[p[i] - 'a'] == 0){
				node temp;
				tr.push_back(temp);
				tr[now].ch[p[i] - 'a'] = tr.size()-1;
//				cout << "add new point: " << tr.size()-1 << '\n';
			}
			now = tr[now].ch[p[i] - 'a'];
//			cout << "now: " << now << '\n';
		}
		tr[now].qhash.push_back(qhid);
	}
	void add_query(string p, string q, int id){
		int now = 0;
		for (int i = 0; i < p.size(); i++){
			if (tr[now].ch[p[i] - 'a'] == 0) break;
			now = tr[now].ch[p[i] - 'a'];
		}
		if (qh[0]) tr[now].query.push_back({qh[0], id});
		unsigned long long re = 0;
		for (int i = 0; i < q.size(); i++){
			re = re * pri + q[i];
			tr[now].query.push_back({qh[re], id});
		}
	}
	void calcans(int x = 0){
		for (int i = 0; i < tr[x].qhash.size(); i++)
			cnt[tr[x].qhash[i]]++;
		for (int i = 0; i < tr[x].query.size(); i++)
			ans[tr[x].query[i].id] += cnt[tr[x].query[i].val];
		for (int i = 0; i < 26; i++)
			if (tr[x].ch[i]) calcans(tr[x].ch[i]);
		for (int i = 0; i < tr[x].qhash.size(); i++)
			cnt[tr[x].qhash[i]]--;
	}
} V[200005];
void getdiff(string a, string b){
	int pre, lst;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]){
			pre = i;
			break;
		}
	for (int i = a.size()-1; i >= 0; i--)
		if (a[i] != b[i]){
			lst = i;
			break;
		}
//	cout << "pre&lst: " << pre << ',' << lst << '\n';
	unsigned long long hasha = gethash(a.substr(pre, lst - pre + 1));
	unsigned long long hashb = gethash(b.substr(pre, lst - pre + 1));
//	cout << hasha << ',' << hashb << '\n';
	if (mp[make_pair(hasha, hashb)] == 0){
		mp[make_pair(hasha, hashb)] = ++cur;
	}
//	cout << "add mp ok\n";
	unsigned long long qhash = gethash(a.substr(lst+1));
	if (qh[qhash] == 0){
		qh[qhash] = ++cur2;
	}
//	cout << "add qh ok\n";
	V[mp[make_pair(hasha, hashb)]].insert(rev(a.substr(0, pre)), qh[qhash]);
}
void solve(string a, string b, int id){
	int pre, lst;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]){
			pre = i;
			break;
		}
	for (int i = a.size()-1; i >= 0; i--)
		if (a[i] != b[i]){
			lst = i;
			break;
		}
	unsigned long long hasha = gethash(a.substr(pre, lst - pre + 1));
	unsigned long long hashb = gethash(b.substr(pre, lst - pre + 1));
	if (mp[make_pair(hasha, hashb)] == 0){
		ans[id] = 0;
		return;
	}
	V[mp[make_pair(hasha, hashb)]].add_query(rev(a.substr(0, pre)), a.substr(lst+1), id);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2) continue;
		getdiff(s1, s2);
	}
	for (int i = 1; i <= q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()){
			ans[i] = 0;
			continue;
		} 
		solve(t1, t2, i);
	}
	for (int i = 1; i <= cur; i++)
		V[i].calcans();
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
	return 0;
}

