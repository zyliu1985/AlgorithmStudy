#include<bits/stdc++.h>
using namespace std;
bool a[500000];
int g[500000];
bool f(int x){
	for(int i=x;i>=1;i--){
		if(!a[i]){
			a[i]=1;
			return 1;
		}
	}
	return 0;
}
int main(){
	int G,P;
	cin>>G>>P;
	for(int i=1;i<=P;i++){
		cin>>g[i];
	}
	for(int i=1;i<=P;i++){
		if(!f(g[i])){
			cout<<i-1;
			return 0;
		}
	}
	cout<<P;
	return 0;
}
/*
4 6 2 2 3 3 4 4
*/
