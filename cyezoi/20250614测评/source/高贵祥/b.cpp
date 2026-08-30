#include<bits/stdc++.h>
using namespace std;
bool c[4][200005];
int main(){
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]){
				ans+=3;
			}
		}
	}
	cout<<ans<<" ";
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]){
				ans-=c[i][j-1]+c[i][j+1];
				if(j%2==1){
					ans-=c[i-1][j]+c[i+1][j];
				}
				cout<<ans<<" ";
			}
		}
	}
	cout<<ans;
	return 0;
}
