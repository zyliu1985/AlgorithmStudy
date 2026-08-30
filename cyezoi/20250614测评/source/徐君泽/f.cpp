#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[3100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[n+i-1];
	}
	sort(a,a+m+n-1);
	int ans=0;
	for(int i=m+n-2;i>=(m+n)/2-1;i--){
		ans+=a[i];
	}
	cout<<ans;
}
