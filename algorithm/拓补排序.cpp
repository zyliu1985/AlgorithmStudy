#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> v[100005];
queue<int> q;
int nf[100005], dis[100005];
bool vis[100005];
void tbpx(){
	for (int i = 1; i <= n; i++)
		if (nf[i] == 0){
			dis[i] = 0;
			vis[i] = true;
			q.push(i);
		}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]]){
				nf[v[x][i]]--;
				dis[v[x][i]] = max(dis[v[x][i]], dis[x] + 1);
				if (nf[v[x][i]] == 0){
					vis[v[x][i]] = true;
					q.push(v[x][i]);
				}
			}
	}
}
int main(){
	
}