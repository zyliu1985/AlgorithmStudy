#include<bits/stdc++.h>
using namespace std;
int n,a[5][200005];
int ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=2;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]) ans+=3;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[1][i]&&a[1][i+1]) ans-=2;
	}
	for(int i=1;i<=n;++i){
		if(a[2][i]&&a[2][i+1]) ans-=2;
		if((i&1)&&a[2][i]&&a[1][i]) ans-=2;
	}
	cout<<ans;
	return 0;
}
