#include<bits/stdc++.h>
using namespace std;


int p[5200];
int a[5200][5200];
int n,mn;
int up(double A){
	if((A-floor(A))>0){
		int k=floor(A)+1;
		return k;
	}
	return A;
}
int fun(int L,int tp){
	int as=0;
	for(int i=1;i<=up(L*1.0/2);i++){
		as+=(max(p[tp+i-1],p[tp+L-i+1-1])-min(p[tp+i-1],p[tp+L-1+1-i]));
	}
	return as;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=1+n-i;j++){
			a[i][j]=fun(i,j);
		}
		mn=a[i][1];
		for(int j=1;j<=1+n-i;j++){
			if(a[i][j]<mn)mn=a[i][j];
		}
		cout<<mn<<' ';
		mn=0;
	}
}
