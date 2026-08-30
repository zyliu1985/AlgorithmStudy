#include<bits/stdc++.h>//AT16.8
#define ll long long
using namespace std;
bool v[2020];
ll k,n,m,ia,ib,it,ih,s,e,d[2020],si[1000010];
struct st{
	ll x,t,h;
}a[1000010];
bool mcmp(st _a,st _b){
	return _a.h==_b.h?_a.t>_b.t:_a.h>_b.h;
}
vector<ll> at[2020],avt[2020],avh[2020];
void mpop(ll _x){
	si[_x]--;
	a[_x].x=0;
	a[_x].t=0;
	a[_x].h=0;
	if(!a[_x*2].x&&!a[_x*2+1].x)return ;
	else if(mcmp(a[_x*2],a[_x*2+1])&&a[_x*2+1].x){
		a[_x]=a[_x*2+1];
		mpop(_x*2+1);
	}
	else{
		a[_x]=a[_x*2];
		mpop(_x*2);
	}
	return;
}
void mpush(ll _p,ll _x,ll _t,ll _h){
	if(!a[_p].x){
		a[_p].x=_x;
		a[_p].t=_t;
		a[_p].h=_h;
		si[_p]++;
	}
	else if(mcmp(a[_p],(st){_x,_t,_h})){
		mpush(_p,a[_p].x,a[_p].t,a[_p].h);
		a[_p].x=_x;
		a[_p].t=_t;
		a[_p].h=_h;
		si[_p]++;
	}
	else if(mcmp(a[_p*2],(st){_x,_t,_h})||!a[_p*2].x){
		mpush(_p*2,a[_p*2].x,a[_p*2].t,a[_p*2].h);
		a[_p*2].x=_x;
		a[_p*2].t=_t;
		a[_p*2].h=_h;
		si[_p]++;
	}
	else if(mcmp(a[_p*2+1],(st){_x,_t,_h})||!a[_p*2+1].x){
		mpush(_p*2+1,a[_p*2+1].x,a[_p*2+1].t,a[_p*2+1].h);
		a[_p*2+1].x=_x;
		a[_p*2+1].t=_t;
		a[_p*2+1].h=_h;
		si[_p]++;
	}
	else if(si[_p*2]>si[_p*2+1]){
		mpush(_p*2+1,_x,_t,_h);
		si[_p]++;
	}
	else{
		mpush(_p*2,_x,_t,_h);
		si[_p]++;
	}
}
void dijkstra(ll _x){
	mpush(1,_x,0,0);
	memset(d,0x7f,sizeof(d));
	d[_x]=0;
	ll to,_t,_h;
	while(1){
		if(!a[1].x)break;
		to=a[1].x;
		_t=a[1].t;
		_h=a[1].h;
		mpop(1);
		if(v[to])continue;
		for(int i=0;i<at[to].size();i++){
			if(d[at[to][i]]>d[to]+avt[to][i]&&_h+avh[to][i]<k){
				d[at[to][i]]=d[to]+avt[to][i];
				mpush(1,at[to][i],d[at[to][i]],_h+avh[to][i]);
			}
		}
	}
	return;
}
int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ia>>ib>>it>>ih;
		if(ia==ib)continue;
		at[ia].push_back(ib);
		avt[ia].push_back(it);
		avh[ia].push_back(ih);
		swap(ia,ib);
		at[ia].push_back(ib);
		avt[ia].push_back(it);
		avh[ia].push_back(ih);
	}
	cin>>s>>e;
	dijkstra(s);
	if(d[e]==d[n+5])cout<<-1;
	else cout<<d[e];
	return 0;
}
