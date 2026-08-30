#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a[3110];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=n;i<n+m;i++){
		cin>>a[i];
	}
	sort(a,a+n+m);
	for(int i=n+m-1;i>=(n+m)/2;i--){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
