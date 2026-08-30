#include<bits/stdc++.h>
using namespace std;
int Cn[5005],C[5005][5005],n,num,h=0,minlen;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Cn[i];
		for(int j=1;j<=i;j++){
			C[i][j]=Cn[i]-Cn[j];
			if(C[i][j]<0){
				C[i][j]=-C[i][j];
			}
		}
	}
	cout<<0<<' ';
	for(int i=1;i<n;i++){
		minlen=100000000;
		for(int j=1;j<n-i+1;j++){
			h=0;
			for(int k=j;k<=j+i;k++){
				h+=C[k][j+i-k+j];
			}
			minlen=min(minlen,h);
		}
		cout<<minlen<<' ';
	}
	return 0;
}
