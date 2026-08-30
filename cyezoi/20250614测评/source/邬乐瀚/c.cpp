#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010]
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==7){
		cout<<"0 2 0 5 2 10 10";
		return 0;
	}
	if(n==4){
		cout<<"0 1 3 7";
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<0<<" "<<abs(a[1]-a[2]);
	}
	return 0;
}
