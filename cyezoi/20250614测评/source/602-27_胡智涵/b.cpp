#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N][2],c,ans;
int main(){
	cin>>c;
	for(int j=0;j<=1;j++)
		for(int i=1;i<=c;i++) cin>>a[i][j];
	for(int i=1;i<=c;i++){
		if(a[i][0]==1){
			if(a[i-1][0]==1){
				ans++;
			}
			else ans+=3;
		}
	}
	for(int i=1;i<=c;i++){
		if(a[i][1]==1){
			if(i%2!=0){
				if(a[i][0]==1 && a[i-1][1]==1) ans--;
				else if(a[i-1][1]==1 || a[i][0]==1) ans++;
				else ans+=3;
			}
			else{
				if(a[i-1][1]==1) ans++;
				else ans+=3;
			}
		}
	}
	cout<<ans;
}
