#include<bits/stdc++.h>
using namespace std;
int a[10],n;
int ans=-1,anspos[10],tail=-1;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		char tmp[10];
		cin>>tmp;
		for(int i=0;i<5;i++){
			if(tmp[i]=='Y') a[i]++;
		}
	}
	for(int i=0;i<5;i++){
		if(a[i]>ans) ans=a[i];
	}
	for(int i=0;i<5;i++){
		if(a[i]==ans) anspos[++tail]=i;
	}
	for(int i=0;i<=tail;i++){
		cout<<anspos[i]+1;
		if(i!=tail) cout<<",";
	}
	
	return 0;
}
/*
3
YY.Y.
...Y.
.YYY.

5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/
