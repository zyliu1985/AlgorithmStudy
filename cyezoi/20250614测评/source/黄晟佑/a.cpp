#include<bits/stdc++.h>
using namespace std;
int n;
struct cat{
	int c,d;
}a[8];
bool cmp(cat x,cat y){
	if(x.c!=y.c) return x.c>y.c;
	return x.d<y.d;
}
string b;
int main(){
	cin>>n;
	a[1].d=1;
	a[2].d=2;
	a[3].d=3;
	a[4].d=4;
	a[5].d=5;
	for(int i=1;i<=n;i++){
		cin>>b;
		for(int j=1;j<=5;j++){
			if(b[j-1]=='Y'){
				a[j].c++;
			}
		}
	}
	sort(a+1,a+6,cmp);
	cout<<a[1].d;
	for(int i=2;i<=5;i++){
		if(a[i].c==a[1].c) cout<<","<<a[i].d;
	}
}
