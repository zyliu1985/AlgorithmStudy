#include<bits/stdc++.h>
using namespace std;
int n;
char a[100005][5];
int ans[6];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
			if(a[i][j]=='Y')ans[j]++; 
		}
	}
	int x=0;
	for(int i=0;i<5;i++){
		x=max(ans[i],x);
	}
	bool flag=false;
	for(int i=0;i<5;i++){
		if(ans[i]==x){
			
			if(flag){
				cout<<",";
			}
			if(!flag){
				flag=true;
			}
			cout<<i+1;
		}
	}
	return 0;
}

