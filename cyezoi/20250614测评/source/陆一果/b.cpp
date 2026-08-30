#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
		cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1)
		cnt++;
	}
	int ans=cnt*3;
	for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i+1]==1)
		ans-=2;
		if(a[i]==1&&b[i]==1&&i%2)
		ans-=2;
		if(b[i]==1&&b[i+1]==1)
		ans-=2;
	}
	cout<<ans;
	return 0;
}
