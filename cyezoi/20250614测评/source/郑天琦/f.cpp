#include<bits/stdc++.h>
using namespace std;
int a[3100];
int main(){
	int m,n,d=0;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[m+i];
	}
	for(int i=0;i<m+n-1;i++){
		for(int j=i+1;j<m+n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<m+n;i++){
		cout<<a[i]<<" ";
	}
	for(int i=0;i<(m+n+1)/2;i++){
		d+=a[i];
	}
	cout<<d;
	return 0;
}
