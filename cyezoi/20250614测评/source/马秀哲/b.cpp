#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2][1200000];
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<2;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[0][i]==1){
		
		ans+=1;
		if(a[0][i+1]==0) ans+=1;
		if(i%2==0) ans+=1;
		else{
			if(a[1][i]==0) ans+=1;
		}}
	}
	for(int i=1;i<=n;i++){
		if(a[1][i]==1){
		
		ans+=1;
		if(a[0][i+1]==0) ans+=1;
		ans+=1;}
	}
	cout<<ans;
	return 0;
}
