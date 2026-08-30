#include <bits/stdc++.h>
using namespace std;
long long n,a[10],maxx,maxb;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string z;
		cin>>z;
		for(int j=0;j<5;j++){
			if(z[j]=='Y'){
				a[j+1]++;
			}
		}
	}
	for(int i=1;i<=5;i++){
		if(a[i]>=maxx){
			maxx=a[i];
			maxb=i;
		}
	}
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			if(i!=maxb){
				cout<<i<<',';
			}else{
				cout<<i;
			}
		}
	}
	return 0;
}
