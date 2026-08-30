#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

string s;
int a[5];

signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int i=0;i<5;i++){
			if(s[i]=='Y')a[i]++;
		}
	}
	
	int ans=max({a[0],a[1],a[2],a[3],a[4]});
	int f=0;
	for(int i=0;i<5;i++){
		if(a[i]==ans){
			if(!f)f=1;
			else cout<<',';
			cout<<i+1;
		}
	}
	
	return 0;
}
