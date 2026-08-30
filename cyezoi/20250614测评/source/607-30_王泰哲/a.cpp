#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int n,ma=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			char c;
			cin>>c;
			if(c=='Y'){
				a[j]++;
			}
		}
	}
	for(int i=0;i<5;i++){
		if(a[i]>ma){
			ma=a[i];
		}
	}
	bool f=false;
	for(int i=0;i<5;i++){
		if(a[i]==ma){
			if(f){
				cout<<",";
			}
			cout<<i+1;
			f=true;
		}
	}
	return 0;
}

