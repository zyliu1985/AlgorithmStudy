#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,n,m,a,b;
struct line{
	int t=LLONG_MAX,h=LLONG_MAX;
};
struct island{
	int vismint=LLONG_MAX,vish=LLONG_MAX,iindex;
	line lines[2100];
};
island islands[11000];
int temp1,temp2,temp3;
signed main(){
	cin>>k>>n>>m;
	for(int i=1;i<=n;i++)islands[i].iindex=i;
	for(int i=1;i<=m;i++){
		cin>>temp1>>temp2;
		cin>>temp3;
		islands[temp1].lines[temp2].t=temp3;
		islands[temp2].lines[temp1].t=temp3;
		cin>>temp3;
		islands[temp1].lines[temp2].h=temp3;
		islands[temp2].lines[temp1].h=temp3;
	}
	cin>>a>>b;
	islands[a].vismint=0,islands[a].vish=0;
	queue<island>Q;
	Q.push(islands[a]);
	while(!Q.empty()){
		island f=Q.front();
		Q.pop();
		if(f.iindex==b){
			islands[b].vismint=min(islands[b].vismint,f.vismint);
		}
		for(int i=1;i<=n;i++){
			if(f.lines[i].t!=LLONG_MAX){
				if(f.vish+f.lines[i].h<k){
					if(islands[i].vismint==f.vismint+f.lines[i].t){
						if(islands[i].vish>f.vish+f.lines[i].h){
							islands[i].vish=f.vish+f.lines[i].h;
							Q.push(islands[i]);
						}
					}
					if(islands[i].vismint>f.vismint+f.lines[i].t){
						islands[i].vismint=f.vismint+f.lines[i].t;
						islands[i].vish=f.vish+f.lines[i].h;
						Q.push(islands[i]);
					}
				}
				
			}
		}
	}
	if(islands[b].vismint!=LLONG_MAX)cout<<islands[b].vismint;
	else cout<<-1;
	return 0;
}
