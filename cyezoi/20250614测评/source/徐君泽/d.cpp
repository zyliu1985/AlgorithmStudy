#include<bits/stdc++.h>
using namespace std;

int g,p,maxn=0;
int vis[100000];
int plane[100000];

void dfs(int id,int step){
	maxn=max(maxn,step);
	for(int i=0;i<plane[id];i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(id+1,step+1);
			vis[i]=0;
		}
	}	
}

int main(){
	cin>>g>>p;
	for(int i=0;i<p;i++) cin>>plane[i];
	dfs(0,0);
	cout<<maxn;
}
