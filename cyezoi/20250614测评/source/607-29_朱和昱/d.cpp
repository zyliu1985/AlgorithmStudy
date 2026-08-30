#include<bits/stdc++.h>
using namespace std;
#define int long long
int g;
int p;
int a[100005];
int x[100005];
signed main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	for(int i=1;i<=g;i++){
		x[i]=i;
	}
	for(int i=1;i<=p;i++){
		int y=a[i];
		while(x[a[i]]!=a[i]){
			a[i]=x[a[i]];
		}
		if(a[i]!=0){
			x[a[i]]=a[i]-1;
			x[y]=a[i]-1;
		}
		else{
			cout<<i-1;
			return 0;
		}
	}
	cout<<p<<endl;
	return 0;
}
