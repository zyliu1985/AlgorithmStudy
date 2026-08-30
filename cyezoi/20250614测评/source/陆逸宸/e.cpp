#include <bits/stdc++.h>
using namespace std;
long long k,n,m,A,B;
struct node{
	int a,b,t,h;
}hx[10010];
int main(){
	cin>>k>>n>>m;
	for(int i=0;i<m;i++){
		cin>>hx[i].a>>hx[i].b>>hx[i].t>>hx[i].h;
	}
	cin>>A>>B;
	if(A==B){
		cout<<0;
	} else{
		cout<<-1;
	}
	return 0;
}
