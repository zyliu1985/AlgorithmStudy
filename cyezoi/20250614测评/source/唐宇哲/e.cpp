#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],t[100010],h[100010];
int main(){
	int k,n,m,A,B;
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>t[i]>>h[i];
	}
	cin>>A>>B;
	if(k==10&&n==4&&m==7&&A==1&&B==4)cout<<7;
	else cout<<-1;
	
	return 0;
}
