#include<bits/stdc++.h>
using namespace std;
#define int long long
int c;
int a[200005][4];
int ans;
signed main(){
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i][1];
	}
	for(int i=1;i<=c;i++){
		cin>>a[i][2];
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=2;j++){
			if(a[i][j]==0) continue;
			if(i&1&&j==1){
				ans+=(a[i][j]-a[i-1][j]+a[i][j]-a[i+1][j]+a[i][j]-a[i][j+1]);
			}
			if(i&1&&j==2){
				ans+=(a[i][j]-a[i-1][j]+a[i][j]-a[i+1][j]+a[i][j]-a[i][j-1]);
			}
			if(i%2==0&&j==1){
				ans+=(a[i][j]-a[i-1][j]+a[i][j]-a[i+1][j]+a[i][j]-a[i][j-1]);
			}
			if(i%2==0&&j==2){
				ans+=(a[i][j]-a[i-1][j]+a[i][j]-a[i+1][j]+a[i][j]-a[i][j+1]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
