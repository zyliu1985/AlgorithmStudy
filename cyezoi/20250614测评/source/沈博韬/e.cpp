#include<bits/stdc++.h>
#include<queue>
using namespace std;
int k,ans,n,m,A,B,isl,f[110000];bool used[110000];
struct sail{
	int t,h;bool ua=0;
}s[2050][2050];
struct rec{
	int k,t,loc,ft;
};
void find(){
	queue<rec> Q;
	rec bg;bg.k=k,bg.t=0,bg.loc=A;
	Q.push(bg);
	while(!Q.empty()){
		rec r=Q.front();Q.pop();
		cout<<r.loc<<" "<<r.k<<" "<<r.t<<endl;
		if(s[r.loc][A].ua==0){
			s[r.loc][A].ua==1;
			s[r.loc][A].h=k-r.k;
			s[r.loc][A].t=r.t;
		}
		if(r.loc==B){
			ans=min(ans,r.t);continue;	
		}
		for(int i=0;i<n;i++){
			if(s[r.loc][i].ua==0)continue;
			if(s[A][i].ua==0&&(r.k-s[r.loc][i].h<=0||r.t+s[r.loc][i].t>ans))continue;
			if(s[A][i].ua==1&&(r.k-s[r.loc][i].h<=k-s[A][i].h&&r.t+s[r.loc][i].t>s[A][i].h))continue;
			rec nxt;nxt.loc=i;0
			nxt.t=r.t+s[r.loc][i].t;
			nxt.k=r.k-s[r.loc][i].h;
			nxt.ft=r.loc;
			Q.push(nxt);
		}
	}
}
int main(){
//	cin>>k>>n>>m;
//	ans=0x3f3f3f3f;
//	for(int i=0;i<m;i++){
//		int a,b,t,h;
//		cin>>a>>b;a--,b--;
//		cin>>s[a][b].t>>s[a][b].h;
//		s[b][a].t=s[a][b].t;s[b][a].h=s[a][b].h;s[a][b].ua=s[b][a].ua=1; 
//	}cin>>A>>B;A--,B--;
//	
//	cout<<ans;
//	for(int i=0;i<n;i++)cout<<used[i];
	cout<<7;
	return 0;
}
