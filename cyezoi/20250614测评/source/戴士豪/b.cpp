#include<bits/stdc++.h>
using namespace std;

int n,a[5][200010],ans=0;

int main(){
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				ans+=3;
				if(j%2==0){
					if(a[i][j-1]==1){
						ans--;
					}
					if(a[i][j+1]==1){
						ans--;
					}
				}
				else{
					if(a[i][j-1]==1){
						ans--;
					}
					if(a[i][j+1]==1){
						ans--;
					}
					if(a[i-1][j]==1){
						ans--;
					}
					if(a[i+1][j]==1){
						ans--;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
