#include<bits/stdc++.h>
using namespace std;

int n,a[200020],b[200020],ans=0;

int main(){
	cin>>n;
	a[0]=0,b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			if(a[i-1]==1) ans+=1;
			else ans+=3;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1){
			if(i%2==1){
				if(a[i]==1 && b[i-1]==1) ans-=1;
				if(a[i]==1 && b[i-1]==0) ans+=1;
				if(a[i]==0 && b[i-1]==1) ans+=1;
				if(a[i]==0 && b[i-1]==0) ans+=3;
			}
			if(i%2==0){
				if(b[i-1]==1) ans+=1;
				else ans+=3;
			}
		}
	}
	cout<<ans;
	return 0;
}
