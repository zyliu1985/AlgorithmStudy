#include<bits/stdc++.h>
using namespace std;
int ans[11];
int n,num=-1,flag;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			char a;cin>>a;
			if(a=='Y')ans[j]++;
		}
	}
	for(int j=0;j<5;j++){
		if(ans[j]>num){
			num=ans[j];
		}
	}	
	for(int i=0;i<5;i++){
		if(flag==0){
			if(ans[i]==num){
				cout<<i+1;flag++;
			}
			continue;
		}
		if(ans[i]==num)cout<<","<<i+1;
	}
	return 0;
}
