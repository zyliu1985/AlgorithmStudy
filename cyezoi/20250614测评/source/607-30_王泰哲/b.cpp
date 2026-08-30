#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,ans=0;
	cin>>c;
	int m[2][c];
	for(int i=0;i<2;i++){
		for(int j=0;j<c;j++){
			cin>>m[i][j];
			ans+=m[i][j]*3;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<c-1;j++){
			if(m[i][j]&&m[i][j+1]){
				ans-=2;
			}
		}
	}
	for(int i=0;i<c;i+=2){
		if(m[0][i]&&m[1][i]){
			ans-=2;
		}
	}
	cout<<ans;
	return 0;
}

