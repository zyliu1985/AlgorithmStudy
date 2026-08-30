#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	int n;
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
	int max=0;
	for(int i=0;i<5;i++){
		if(a[i]>max)
		max=a[i];
	}
	int f=0;
	for(int i=0;i<5;i++){
		if(a[i]==max){
			if(f==1){
				cout<<',';
			}
			cout<<i+1;
			f=1;
		}
	}
}
