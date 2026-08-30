#include<bits/stdc++.h>
using namespace std;
int n;
int a[6];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		for(int i=1;i<=5;i++){
			cin>>c;
			if(c=='Y'){
				a[i]++;
			}
		}
	}
	int maxx=-1;
	for(int i=1;i<=5;i++){
		maxx=max(maxx,a[i]);
	}
	int ii=0;
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			cout<<i;
			ii=i;
			break;
		}
	}
	for(int i=ii+1;i<=5;i++){
		if(a[i]==maxx){
			cout<<","<<i;
		}
	}
	return 0;
}
