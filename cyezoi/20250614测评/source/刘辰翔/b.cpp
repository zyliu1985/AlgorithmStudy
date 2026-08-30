#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200010],b[200010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(a[i-1]==1)ans++;
			else ans+=3;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			ans+=3;
			if(b[i-1]==1)ans-=2;
			if(a[i]==1 && i%2==1)ans-=2;
		}
	}
	cout<<ans;
}
