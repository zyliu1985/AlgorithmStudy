#include<bits/stdc++.h>
using namespace std;
int k,n,m,a,b;
int t[2010][2010],h[2010][2010];
bool f[2010];
int bfs(int pos,int time,int rest){
	if(rest<=0) return -1;
	if(f[pos]) return -1;
	if(pos==b) return time;
	
	f[pos] = true;
	int ans=-1;
	for(int i=0;i<=n;i++){
		if(t[pos][i]!=-1 and h[pos][i]!=-1){
			int tans=bfs(i,time+t[pos][i],rest-h[pos][i]);
			if(ans==-1) ans = tans;
			else if(tans!=-1) ans = min(ans,tans);
		}
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(t,-1,sizeof(t));
	memset(h,-1,sizeof(h));
	cin>>k>>n>>m;
	for(int i=0;i<m;i++){
		int ta,tb,tt,th;
		cin>>ta>>tb>>tt>>th;
		t[ta][tb] = tt;
		t[tb][ta] = tt;
		h[ta][tb] = th;
		h[tb][ta] = th;
	}
	cin>>a>>b;
	cout<<bfs(a,0,k);
	return 0;
}
/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/

