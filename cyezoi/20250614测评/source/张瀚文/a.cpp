#include <bits/stdc++.h>
using namespace std;
int a[6];
int main(){
	int n,ans=-1,id;
	char c;
	bool flag=false;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y') a[j]++;
		}
	}
	for(int i=1;i<=5;i++){
		ans=max(ans,a[i]);
	}
	for(int i=1;i<=5;i++){
		if(a[i]==ans){
			if(flag==false) flag = true;
			else cout<<",";
			cout<<i;
		}
	}
	return 0;
}
