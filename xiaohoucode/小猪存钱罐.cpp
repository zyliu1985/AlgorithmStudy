#include <iostream>
#include <vector>
using namespace std;

vector<int> v[800005];
int ans;
bool vis[800005];
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i]]){
			vis[v[x][i]] = true;
			dfs(v[x][i]);
		}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]){
			ans++;
			dfs(i);
		}
	cout << ans << endl;
	return 0;
}