#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool s[2][200005];
int main(){
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
			if(s[i][j]==1)ans+=3;
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(i==1&&s[i][j]==1){
				if(s[i+1][j]==1&&j%2==1)ans-=2;
				if(j!=n&&s[i][j+1]==1)ans-=2;
			}
			else if(i==2&&s[i][j]==1){
				if(j!=n&&s[i][j+1]==1)ans-=2;
			}
		}
	}
	cout<<ans;
	return 0;
}
