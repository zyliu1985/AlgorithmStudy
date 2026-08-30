#include<bits/stdc++.h>
using namespace std;

int n,maxx;

struct fay{
	int num;
	int t;
}m[100006];

bool cmp(fay x,fay y){
	return x.t>y.t;
}

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=5;i++){
			char a;
			cin>>a;
			m[i].num=i;
			if(a=='Y') m[i].t++;
		}
	}
	sort(m+1,m+6,cmp);
	maxx=m[1].t;
	cout<<m[1].num;
	for(int i=2;i<=5;i++){
		if(m[i].t==maxx) cout<<","<<m[i].num;
	}
	
	return 0;
}
