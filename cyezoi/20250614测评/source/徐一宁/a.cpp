#include<bits/stdc++.h>
using namespace std;

int a[10]={},ans[10]={};
long long mx=-1,n;

char x;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>x;
			if(x=='Y'){
				a[j]++;
			}
		}	
	}
	int k=1;
	for(int i=1;i<=5;i++){
		if(mx<a[i]){
			mx=a[i];
			ans[k]=i;
		}
		else if(mx==a[i]){
			k++;
			ans[k]=i;
		}
	}
	for(int i=1;i<=5;i++){
		
		if(ans[i]!=0){
			cout<<ans[i];
		}
		if(ans[i+1]!=0){
			cout<<",";
		}
		else if(ans[i+1]==0){
			break;
		}
	}
	return 0;
}
