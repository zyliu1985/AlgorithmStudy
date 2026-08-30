#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool x[200006][4];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i][1];
	for(int i=1;i<=n;i++) cin>>x[i][2];
	for(int i=1;i<=n;i++){
		if(x[i][1]){
			ans+=3;
			if(x[i-1][1]) ans--;
			if(x[i+1][1]) ans--;
			if(i%2==1){
				if(x[i][2]) ans--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i][2]){
			ans+=3;
			if(x[i-1][2]) ans--;
			if(x[i+1][2]) ans--;
			if(i%2==1){
				if(x[i][1]) ans--;
			}
		}
	}
	cout<<ans;
}
