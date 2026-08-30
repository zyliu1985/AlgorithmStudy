#include<bits/stdc++.h>
using namespace std;
int g[100000],p[100000];
int main(){
	int a,b;
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>p[i];
	}
	for(int i=0;i<b;i++){
		for(int j=p[i]-1;j>=0;j--){
			if(g[j]==0){
				g[j]=1;
				break;
			}
			if(j==0){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<b;
	return 0;
}
