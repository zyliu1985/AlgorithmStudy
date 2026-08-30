#include<bits/stdc++.h>
using namespace std;

int c,ans;
int a[3][200006];

int main(){

	cin>>c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			if(a[i][j]==1){
				ans+=3;
				if(i!=2&&j%2==1){
					if(a[i+1][j]==1) ans-=2;
				}
				if(j!=c){
					if(a[i][j+1]==1){
						ans-=2;
					}
				}
			}
			
		}
	}
	cout<<ans;
	
	return 0;
} 
