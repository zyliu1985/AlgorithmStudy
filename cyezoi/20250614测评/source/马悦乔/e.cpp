#include<bits/stdc++.h>
using namespace std;
int k,n,m;
int A,B;
int min_=100000;
int vis[205]= {0};
struct ship {
	int a,b,t,h;
} arr[10005];
void dfs(int island,int damage,int time) {
	if(island==B&&damage<k) {
		min_=min(min_,time);
		return;
	}
	if(time>min_||damage>=k||vis[island]==1)return;
	vis[island-1]=1;
	for(int i=0; i<m; i++) {
		if(island==arr[i].a&&vis[arr[i].b-1]==0)dfs(arr[i].b,damage+arr[i].h,time+arr[i].t);
		if(island==arr[i].b&&vis[arr[i].a-1]==0)dfs(arr[i].a,damage+arr[i].h,time+arr[i].t);
	}
	vis[island-1]=0;
}
int main() {
	cin>>k>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>arr[i].a;
		cin>>arr[i].b;
		cin>>arr[i].t;
		cin>>arr[i].h;
	}
	cin>>A>>B;
	dfs(1,0,0);
	if(min_=100000)cout<<-1;
	else cout<<min_;
	return 0;
}
