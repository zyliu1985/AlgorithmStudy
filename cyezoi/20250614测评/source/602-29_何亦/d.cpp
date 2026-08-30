#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
struct node{
	int l,r,maxx;
}a[maxn*4];
void init(int l,int r,int id){
	a[id]={l,r,r};
	if(l==r)return;
	int mid=(l+r)>>1;
	init(l,mid,id<<1);
	init(mid+1,r,id<<1|1);
}
void push_up(int id){
	a[id].maxx=max(a[id<<1].maxx,a[id<<1|1].maxx);
}
int ask(int l,int r,int id){
	if(l<=a[id].l && a[id].r<=r){
		return a[id].maxx;
	}
	int ans=-1;
	if(l<=a[id<<1].r){
		ans=max(ans,ask(l,r,id<<1));
	}
	if(r>=a[id<<1|1].l){
		ans=max(ans,ask(l,r,id<<1|1));
	}
	return ans;
}
void modify(int pos,int id){
	if(a[id].l==a[id].r){
		a[id].maxx=-1;
		return;
	}
	if(pos<=a[id<<1].r){
		modify(pos,id<<1);
	}else{
		modify(pos,id<<1|1);
	}
	push_up(id);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	init(1,n,1);
	for(int i=1;i<=m;i++){
		int num;
		cin>>num;
		int tmp=ask(1,num,1);
		if(tmp==-1){
			cout<<i-1;
			return 0;
		}
		modify(tmp,1);
	}
	cout<<m;
	return 0;
}
/*
4
3
4
1
1

*/
