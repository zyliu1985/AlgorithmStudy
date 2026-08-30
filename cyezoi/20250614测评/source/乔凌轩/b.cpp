#include<bits/stdc++.h>
using namespace std;
bool a[400010];
long long ans,n;
int main() {
	cin>>n;
	for(int i=1; i<=2*n; i++) {
		cin>>a[i];
		if(a[i]==1){
			ans+=3;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1 && a[i+1]==1){
			ans-=2;
		}
	}
	for(int i=n;i<=2*n;i++){
		if(a[i]==1 && a[i+1]==1){
			ans-=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1 && a[i+n]==1){
			ans-=2;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 1 0 1 0 1 0 0 0 0 0
7 0 0 1 1 0 1 0 0 0 1 0 1 0 0
*/
