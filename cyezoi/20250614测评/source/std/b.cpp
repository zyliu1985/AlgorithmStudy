#include<bits/stdc++.h>
using namespace std;
int n,cnt,tot;
int a[200005],b[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i])cnt++;
	}
	for(int i=1;i<=n;i++){
		if(i<n&&a[i]&&a[i+1])tot++;
		if(i<n&&b[i]&&b[i+1])tot++;
		if(i%2==1&&a[i]&&b[i])tot++;
	}
	cout<<cnt*3-tot*2;  //三角形边数-共边量，每共一条边要减两条边 
	return 0;
}  
/*
# P9302 2023J4/S1 思维

思维 

*/
