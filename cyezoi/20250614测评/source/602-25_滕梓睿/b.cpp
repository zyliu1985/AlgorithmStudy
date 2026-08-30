#include<bits/stdc++.h>
using namespace std;
int c;
int a[200001][3];
int main(){
	int ans=0;
	cin>>c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			cin>>a[j][i];
			if(a[j][i]==1){
				ans+=3;
				if(a[j-1][i]==1){
					ans-=2;
				}
				if(a[j][i-1]==1&&j%2==1){
					ans-=2;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
