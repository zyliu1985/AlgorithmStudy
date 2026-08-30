#include<bits/stdc++.h>
using namespace std;
int a[30000],stop[30000],sback[30000];
int f(int l,int r){
	int cnt=0;
	while(l<=r){
		cnt+=abs(a[l]-a[r]);
		l++;r--;
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		stop[i]=stop[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		sback[i]=sback[i+1]+a[i];
	}
	cout<<0<<' ';
	for(int i=3;i<=n;i++){
		int maxs=0,l,r;
		for(int j=0;j<=n&&i+j<=n+1;j++){
			int k=i+j;
			if(maxs<stop[j]+sback[k]){
				maxs=stop[j]+sback[k];
				l=1+j;
				r=k-1;
			}
		}
		cout<<f(l,r)<<' ';
	}
	cout<<f(1,n);
	return 0;
}
/*
7
3 1 4 1 5 9 2
*/
