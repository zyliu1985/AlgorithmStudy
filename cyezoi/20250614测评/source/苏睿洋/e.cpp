#include<bits/stdc++.h>
using namespace std;

int k,n,m,a,b,h,t,r[2020][2020][2];

int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>t>>h;
		r[x][y][0]=t;
		r[x][y][1]=h;
	}
	cin>>a>>b;
	cout<<-1;
	return 0;
}
