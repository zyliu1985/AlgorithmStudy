#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005][2];
int main(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		if(a[i][0]==1){
			if(a[i-1][0]==1){
				ans+=1;
			}
			else{
				ans+=3;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		if(a[i][1]==1){
			ans+=3;
			if(a[i-1][1]==1){
				ans-=2;
			}
			if(a[i][0]==1&&i%2==1){
				ans-=2;
			}
		}
	}
	cout<<ans;
	return 0;
}
