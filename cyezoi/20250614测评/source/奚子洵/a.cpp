#include<bits/stdc++.h>
using namespace std;

int n,b[10],maxn,ans[10],top=1;
char c;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y'){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=5;i++){
		maxn=max(maxn,b[i]);
	}
	for(int i=1;i<=5;i++){
		if(maxn==b[i]){
			ans[top]=i;
			top++;
		}
	}
	for(int i=1;i<top-1;i++){
		cout<<ans[i]<<",";
	}
	cout<<ans[top-1];
	return 0;
}

