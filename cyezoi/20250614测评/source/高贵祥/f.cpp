#include<bits/stdc++.h>
using namespace std;
int a[3005],b[105],f[3105];
int main(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	f[1]=a[1],f[2]=a[2];
	for(int i=3;i<=n;i++){
		f[i]=max(f[i-2]+a[i],f[i-1]);
	}
	cout<<f[n];
	return 0;
}
