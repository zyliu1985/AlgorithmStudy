#include<bits/stdc++.h>
using namespace std;
int n,a[5],maxx=-1,maxidx;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			char c;
			cin>>c;
			if(c=='Y') a[j]++;
		}
	}
	for(int j=0;j<5;j++)
		if(a[j]>maxx){
			maxx=a[j];
			maxidx=j;
		}
	cout<<maxidx+1;
	for(int i=0;i<5;i++)
		if(a[i]==maxx and maxidx!=i) cout<<","<<i+1;
	return 0;
}
