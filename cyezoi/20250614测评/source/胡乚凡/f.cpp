#include<bits/stdc++.h>
using namespace std;
int n,m;
int m1;
int a[3105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1,cmp);
	cin>>m;
	
	if(m==0){
		for(int i=1;i<=n/2+(n+m)%2;i++){
			ans+=a[i];
		}
		cout<<ans;
	}else if(m==1){
		cin>>m1;
		a[n+1]=m1;
		sort(a+1,a+n+2,cmp);
		for(int i=1;i<=(n+1)/2+(n+m)%2;i++){
			ans+=a[i];
		}
		cout<<ans;
	}else{
		for(int i=n+1;i<=n+m;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+m+1,cmp);
		for(int i=1;i<=(n+m)/2+(n+m)%2;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
