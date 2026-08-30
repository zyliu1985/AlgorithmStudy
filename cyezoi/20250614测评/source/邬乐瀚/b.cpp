#include<bits/stdc++.h>
using namespace std;
int c;
int t[200010][2];
int ans;
int main(){
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>t[i][0];
		if(t[i][0]==1){
			ans+=3;
		}
	}
	for(int i=1;i<=c;i++){
		cin>>t[i][1];
		if(t[i][1]==1){
			ans+=3;
		}
	}
	for(int i=1;i<c;i++){
		if(t[i][0]==1&&t[i+1][0]==1){
			ans-=2;
		}
		if(t[i][1]==1&&t[i+1][1]==1){
			ans-=2;
		}
		if(t[i][0]==1&&t[i][1]==1&&i%2==1){
			ans-=2;
		}
	}
	if(t[c][0]==1&&t[c][1]==1&&c%2==1){
		ans-=2;
	}
	cout<<ans;
	return 0;
}
