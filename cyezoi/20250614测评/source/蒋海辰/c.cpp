#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,mn,jie,jie1;
	int h[5001];
	cin>>n;//7
	for(int i=1;i<=n;i++){
		cin>>h[n];//3 1 4 1 5 9 2
	}
	for(int i=1;i<=n;i++){//2
		mn=10e5-1;
		for(int p=1;p<n-i+1;p++){//1 2
			jie1=p,jie=0;
		    for(int o=p;o<(p+i)/2;o++){//2 <4
		    	jie+=max(h[o/*1  3*/],h[o+jie1+i-2]/*1*/)-min(h[o],h[o+jie1+i-2]);
		    	jie1-=2;
		    	//cout<<jie<<" ";
			}
			if(jie<mn){
				mn=jie;
			}
        }
        cout<<mn<<" ";
 	}
	return 0;
}
