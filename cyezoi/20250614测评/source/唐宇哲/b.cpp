#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main(){
	int n,ans=0,ansl=0,ansf=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&a[i-1]==0)ans+=3;
		else if(a[i]==1&&a[i-1]==1)ans+=1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1&&b[i-1]==0)ansl+=3;
		else if(b[i]==1&&b[i-1]==1)ansl+=1;
	}
	ansf=ans+ansl;
	for(int i=1;i<=n;i+=2){
		if(a[i]==1&&b[i]==1)ansf-=2;
	}
	cout<<ansf;
	return 0;
}
