#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
long long num0, num1;
bool s[500005];
vector<int> v[500005];
vector<bool> w[500005];
void dfs(int x, int fa){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			s[v[x][i]] = s[x] ^ w[x][i];
			if (s[v[x][i]]) num1++;
			else num0++;
			dfs(v[x][i], x);
		}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		num0 = 1, num1 = 0;
		cin >> n;
//		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++) v[i].clear(), w[i].clear();
		for (int i = 1; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			v[x].push_back(y);
			v[y].push_back(x);
			w[x].push_back(z % 2);
			w[y].push_back(z % 2);
		}
		s[1] = 0;
		dfs(1, 0);
		cout << num0 * num0 * num0 + num1 * num1 * num1 << '\n';
	}
	return 0;
}



