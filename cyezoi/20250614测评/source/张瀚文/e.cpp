#include <bits/stdc++.h>
using namespace std;
#define ll long long

int k,n,m,stp,enp;
struct node{
	int t,h;
} rts[2001][2001];
bool exist[2001][2001],ud[2001];
	

int F(int x,int ms,int time){
	if(ms>=k) return 10e7;
	if(x==enp) return time;
	int ans=10e8;
	ud[x]=1;
	for(int i=1;i<=n;i++){
		if(ud[i]==1) continue;
		if(exist[i][x] == 0) continue;
		ans = min(F(i, ms+rts[i][x].h, rts[i][x].t),ans);
	}
	time += ans;
	ud[x]=0;
	return time;
}

bool cmp(int oh,int ot,int nh,int nt){
	if(oh<nh && ot<nt) return 0;
	if(oh>nh && ot>nt) return 1;
	else{
		if(ot<nt) return 0;
		else return 1;
	}
}

int main(){
	cin>>k>>n>>m;
	int a,b,c,d;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c>>d;
		if(c>k) continue;
		if(exist[a][b]==1){
			if(cmp(rts[a][b].t,rts[a][b].h,c,d)==0) continue;
		}
		exist[a][b]=true;
		exist[b][a]=true;
		rts[a][b].t=c;
		rts[a][b].h=d;
		rts[b][a].t=c;
		rts[b][a].h=d;
	}
	cin>>stp>>enp;
	cout<<F(stp,0,0);
	return 0;
} 

/*
10 4 7 1 2 4 4 1 3 7 2 3 1 8 1 3 2 2 2 4 2 1 6 3 4 1 1 1 4 6 12 1 4
*/
