#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
int cnt = 0,n,k,m;
int min_t[N];//DJ斯特拉来骗分 
bool vis[N];
int ge[N];//标记过的点 
struct node{
	int to,t;
};
vector <node> a[N];
void DJ(){
	int fromf = 0;
	node now = {0,1e9};
	for(int i = 1;i <= cnt;i++){
		for(auto it:a[ge[i]]){
			if(vis[it.to]) continue;
			if(it.t + min_t[ge[i]] <= now.t){
				now = it;
				fromf = ge[i];
			}
		}
	}
	//printf("XX\n");
	if(now.to == 0){
		//printf("end\n");
		return;
	}
	int tof = now.to,tf = now.t;
	min_t[tof] = min_t[fromf]+tf;
	ge[++cnt] = tof;
	vis[tof] = 1;
	return;
}
int main(){
	memset(min_t,0x3f,sizeof(min_t));
	scanf("%d %d %d",&n,&k,&m);
	for(int i = 1;i <= m;i++){
		int x,y,t,h;
		scanf("%d %d %d %d",&x,&y,&t,&h);
		if(h>0) continue;
		a[x].push_back(node{y,t});
		a[y].push_back(node{x,t});
	}
	int st,en;
	scanf("%d %d",&st,&en);
	cnt = 1;
	min_t[st] = 0;
	ge[1] = st;
	vis[st] = 1;
	DJ();
	if(min_t[en] >= 1e9) printf("-1\n");
	else printf("%d\n",min_t[en]);
	return 0;
}

/*
//       ______
//|     |     
//|     |     
//|_____|______
//      |     |
//      |   　|
//______|     |
//       ______
//|     |     
//|     |     
//|_____|______
//      |     |
//      |   　|
//______|     |
//       ______
//|     |     
//|     |     
//|_____|______
//      |     |
//      |   　|
//______|     |
*/
