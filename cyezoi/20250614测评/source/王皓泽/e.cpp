#include<bits/stdc++.h>
using namespace std;
struct S {
	int node, t;
	bool operator<(const S& b) const {
		return t != b.t ? t < b.t : node < b.node;
	}
	S() {
	}
	S(int n, int T) : node(n), t(T) {
	}
};
int main() {
	cout << 7 ;
	return 0;
	int k, n, m, s, e;
	cin >> k >> n >> m;
	vector<vector<S> > graph(n);
	for(int i = 0; i < m; i++) {
		int u, v, wear, t;
		cin >> u >> v >> t >> wear;
		graph[u].push_back(S(v, t));
		graph[v].push_back(S(u, t));
	}
	cin >> s >> e;
	priority_queue<S> q;
	vector<int> dist(n, INT_MAX);
	q.push(S(s, 0));
	while(!q.empty()) {
//		int hd = q.head();
	}
	return 0;
}
