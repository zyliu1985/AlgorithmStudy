#include<bits/stdc++.h>//Kytoias
#define ll long long
using namespace std;
char c;
ll n,ans,a[5][200020];
int main(){
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			if(c=='1'){
				a[i][j]=1;
				ans+=3;
			}
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<n;j++){
			if(a[i][j]&&a[i][j+1])ans-=2;
		}
	}
	for(int i=1;i<=n;i+=2){
		if(a[1][i]&&a[2][i])ans-=2;
	}
	cout<<ans;
	return 0;
}
