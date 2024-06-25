#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int c[105], u[105], rd[105], out[105];
bool vis[105];
vector<int> v[105], w[105];
stack<int> st;
int n, p;
void tbpx(){
	int cur = 0;
	for (int i = 1; i <= n; i++)
		if (rd[i] == 0){
			vis[i] = true;
			st.push(i);
		}
	while (!st.empty()){
		int x = st.top();
		st.pop();
		if (v[x].size() == 0) out[++cur] = x;
		if (c[x] > 0){
			for (int i = 0; i < v[x].size(); i++)
				if (!vis[v[x][i]]){
					rd[v[x][i]]--;
					c[v[x][i]] += c[x] * w[x][i];
					if (rd[v[x][i]] == 0){
						c[v[x][i]] -= u[v[x][i]];
						vis[v[x][i]] = true;
						st.push(v[x][i]);
					}
				}
		} else {
			for (int i = 0; i < v[x].size(); i++)
				if (!vis[v[x][i]]){
					rd[v[x][i]]--;
					if (rd[v[x][i]] == 0){
						vis[v[x][i]] = true;
						st.push(v[x][i]);
					}
				}
		}
	}
	sort(out+1, out+cur+1);
	bool flag = true;
	for (int i = 1; i <= cur; i++)
		if (c[out[i]] > 0){
			flag = false;
			cout << out[i] << ' ' << c[out[i]] << endl;
		}
	if (flag) cout << "NULL" << endl;
}
int main(){
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> c[i] >> u[i];
	for (int i = 1; i <= p; i++){
		int a, b, ww;
		cin >> a >> b >> ww;
		v[a].push_back(b);
		w[a].push_back(ww);
		rd[b]++;
	}
	tbpx();
	return 0;
}