#include<bits/stdc++.h>
using namespace std;
int n;
int a[5];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			char x;
			cin>>x;
			if(x=='Y'){
				a[j]++;
			}
		}
	}
	int x=max(a[0],max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]));
	bool flag=false;
	for(int i=0;i<5;i++){
		if(a[i]==x){
			if(flag){
				cout<<',';
			}
			if(flag==false)flag=true;
			cout<<i+1;
		}
	}
	return 0;
}
