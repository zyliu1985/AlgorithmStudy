#include<bits/stdc++.h>
using namespace std;
int f[210000],n;char tmp;
bool w[2][210000];
int type[2][16]={{0,0,0,0,3,1,3,1,3,3,1,1,4,2,2,0},{0,0,0,0,3,1,3,1,3,3,1,1,6,4,4,2}};
int main(){
	cin.tie(0);
	cin>>n;
	for(int j=0;j<2;j++){
		for(int i=0;i<n;i++){
			cin>>tmp;
			w[j][i]=(tmp=='1');
		}	
	}
	if(w[0][0]==1&&w[1][0]==1)f[0]=4;
	else if(w[0][0]==1||w[1][0]==1)f[0]=3;
	else f[0]=0;
	for(int i=1;i<n;i++){
		int v=0;
		if(w[0][i-1]==1)v+=1;
		if(w[1][i-1]==1)v+=2;
		if(w[0][i]==1)v+=4;
		if(w[1][i]==1)v+=8;
		//cout<<v<<" ";
		f[i]=f[i-1]+type[i%2][v];
	}
	for(int i=0;i<n;i++)cout<<f[i]<<" ";
	
	return 0;
}
