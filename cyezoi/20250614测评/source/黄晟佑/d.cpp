#include<bits/stdc++.h>
using namespace std;
bool b[100006];
bool check(int x){
	while(x>0){
		if(b[x]==0){
			b[x]=1;
			return 0;
		}
		x--;
	}
	return 1;
}
int n,m,a;
int main(){
	cin>>n>>m;
	for(int i=1;i<=min(n,m);i++){
		cin>>a;
		if(check(a)){
			cout<<i-1;
			return 0;
		}
	}
	cout<<min(n,m);
}
