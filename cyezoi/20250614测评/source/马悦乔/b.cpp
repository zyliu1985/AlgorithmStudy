#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[2][200005];
int p(int i,int j,int n) {
	if(i<0||j>n||i>2||j<0)return 0;
	return a[i][j];
}
int main() {
	cin>>n;
	for(int i=0; i<2; i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(a[i][j]==1)cnt+=3;
		}
	}
	for(int i=0; i<2; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]==1) {
				cnt-=p(i-1,j,n);
				cnt-=p(i,j-1,n);
				cnt-=p(i,j+1,n);
				cnt-=p(i+1,j,n);
			}
		}
	}
	cout<<cnt;
	return 0;
}
