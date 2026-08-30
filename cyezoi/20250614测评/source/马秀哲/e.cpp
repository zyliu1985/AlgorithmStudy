#include<bits/stdc++.h>
#define int long long
using namespace std;

struct nm{
	int r,t,y,u;
}e[1200000];

int f[1200000];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(nm a,nm b){
	return (a.u+a.y)<(b.u+b.y);
}
signed main(){
	int k,n,m;
	cin>>k>>n>>m;
	for(int i=0;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].r>>e[i].t>>e[i].u>>e[i].y;
	}
	int a,b;
	cin>>a>>b;
	int ans=0,cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int o=e[i].r;
		int p=e[i].t;
		o=find(o);
		p=find(p);
		if(o!=p){
			f[o]=p;
			ans+=e[i].u;
			cnt+=e[i].y;
			if(find(a)==find(b)){
				if(cnt>=k){
					cout<<-1;
					return 0;
				}
				cout<<ans;
				return 0; 
			}
		}
	}
	cout<<-1;
	return 0;
}
