#include<bits/stdc++.h>
using namespace std;

int n,mx,x[10],b=0;
char c;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y') x[j]++;
		}
	}
	for(int j=1;j<=5;j++) mx=max(mx,x[j]);
	for(int j=1;j<=5;j++){
		if(x[j]==mx){
			if(b==0) cout<<j,b=1;
			else cout<<","<<j;
		}
	}
	return 0;
}
