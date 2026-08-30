#include<bits/stdc++.h>
using namespace std;

int a[205000];
int b[205000];
int c,ans=0;
int main(){
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];
		if(a[i]==1){
			ans+=3;
		}
	}
	for(int i=1;i<=c;i++){
		cin>>b[i];
		if(b[i]==1){
			ans+=3;
		}
	}
	for(int i=1;i<=c;i++){
		if(a[i]==1){
			if(a[i+1]==1){
				ans-=2;
			}
			if(b[i]==1){
				ans-=2;
			}
		}	
	}
	for(int i=1;i<=c;i++){
		if(b[i]==1&&b[i+1]==1){
			ans-=2;
		}	
	}
	cout<<ans;
}
