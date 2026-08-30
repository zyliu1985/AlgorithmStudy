#include<bits/stdc++.h>
using namespace std;

int c,ans;
char a[10][200009];

int main(){
	cin>>c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
			a[0][j]='0';
			a[3][j]='0';
		}
	}
	a[1][0]='0';
	a[1][c+1]='0';
	a[2][0]='0';
	a[2][c+1]='0';
	for(int i=1;i<=c;i++){
		if(a[1][i]=='1'){
			if(i%2==1){
				if(a[1][i-1]=='0'){
					ans++;
				}
				if(a[1][i+1]=='0'){
					ans++;
				}
				if(a[2][i]=='0'){
					ans++;
				}
			}else{
				if(a[1][i-1]=='0'){
					ans++;
				}
				if(a[1][i+1]=='0'){
					ans++;
				}
				if(a[0][i]=='0'){
					ans++;
				}
			}
		}
	}
	for(int i=1;i<=c;i++){
		if(a[2][i]=='1'){
			if(i%2==1){
				if(a[2][i-1]=='0'){
					ans++;
				}
				if(a[2][i+1]=='0'){
					ans++;
				}
				if(a[1][i]=='0'){
					ans++;
				}
			}else{
				if(a[2][i-1]=='0'){
					ans++;
				}
				if(a[2][i+1]=='0'){
					ans++;
				}
				if(a[3][i]=='0'){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

