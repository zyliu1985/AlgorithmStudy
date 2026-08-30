#include<bits/stdc++.h>
using namespace std;
int a[500000],b[500000],f[500000][2];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=f[i-1][0]+a[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	cout<<max(f[n][0],f[n][1]);
	return 0;
}
