#include<bits/stdc++.h>
using namespace std;
int C[4][200005],n,num=0;
int main(){
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>C[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(C[i][j]==1){
				num+=3;
					if(C[i][j-1]==1){
						num-=1;
					}
					if(C[i][j+1]==1){
						num-=1;
					}
					if(j%2==1){
						if(C[i-1][j]==1){
							num-=1;
						}
						if(C[i+1][j]==1){
							num-=1;
						}
					}
			}
		}
	}
	cout<<num;
	return 0;
}
