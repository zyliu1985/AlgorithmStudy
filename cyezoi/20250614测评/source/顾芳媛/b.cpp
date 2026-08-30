#include<bits/stdc++.h>
using namespace std;
int c,ans=0;
bool w[5][200010];
int main(){
	cin>>c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			cin>>w[i][j];
			if(w[i][j]==1){
				ans+=3;
			}
		}
	}
	for(int i=1;i<=c;i++){
		if(w[1][i]==1){
			if(w[1][i-1]==1){
				ans--;
			}
			if(w[1][i+1]==1){
				ans--;
			}
			if(i%2==1 && w[2][i]==1){
				ans--;
			}
		}
		if(w[2][i]==1){
			if(w[2][i-1]==1){
				ans--;
			}
			if(w[2][i+1]==1){
				ans--;
			}
			if(i%2==1 && w[1][i]==1){
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}
