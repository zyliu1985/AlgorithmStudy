#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

struct node{
	int x, w;
};
int dis[10005], n, m, s;
bool vis[10005];
vector<node> v[10005];
queue<int> q;
void spfa(){
	q.push(s);
	vis[s] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	while (!q.empty()){
		int x = q.front();
		vis[x] = false;
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i].x] > dis[x] + v[x][i].w){
				dis[v[x][i].x] = dis[x] + v[x][i].w;
				if (!vis[v[x][i].x]){
					q.push(v[x][i].x);
					vis[v[x][i].x] = true;
				}
			}
	}
}
int main(){
	
}