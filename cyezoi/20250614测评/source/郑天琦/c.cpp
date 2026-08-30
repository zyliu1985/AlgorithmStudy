#include<bits/stdc++.h>
using namespace std;
int h[5000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	for(int i=0;i<n;i++){
		int b=250000000;
		for(int j=0;j<n-i;j++){
			int a=0;
			for(int k=j;k<(j+i+1)/2;k++){
				a+=abs(h[k]-h[j+i-k]);
			}
			if(a<b){
				b=a;
			}
		}
		cout<<b;
		if(i<n-1){
			cout<<" ";
		}
	}
	return 0;
}
