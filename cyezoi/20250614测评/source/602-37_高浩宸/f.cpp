#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ansn,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=n+1;i<n+m+1;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+m+1);
	if((n+m)%2==0){
		ansn=(n+m)/2;
	}else{
		ansn=(n+m)/2+1;
	}
	for(int i=n+m+1;i>=n+m+1-ansn;i--){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
