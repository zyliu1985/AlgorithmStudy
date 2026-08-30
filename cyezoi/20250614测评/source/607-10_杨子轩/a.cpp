#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
int ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char c;
			cin>>c;
			if(c=='Y') a[j]++;
		}
	}
	for(int i=1;i<=5;i++)ans=max(ans,a[i]);
	bool flag=0;
	for(int i=1;i<=5;i++) {
		if(a[i]==ans){
			if(flag) cout<<","<<i;
			else flag=1,cout<<i;
		}
	}
	return 0;
}
