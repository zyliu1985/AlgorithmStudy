#include<bits/stdc++.h>
using namespace std;
int a[200000][2];
int main(){
	int c,b=0;
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>a[i][0];
	}
	for(int i=0;i<c;i++){
		cin>>a[i][1];
	}
	for(int i=0;i<c;i++){
		if(a[i][0]==1){
			b+=3;
			if(a[i-1][0]==1){
				b-=1;
			}
			if(a[i+1][0]==1){
				b-=1;
			}
			if(a[i][1]==1&&i%2==0){
				b-=1;
			}
		}
	}
	for(int i=0;i<c;i++){
		if(a[i][1]==1){
			b+=3;
			if(a[i-1][1]==1){
				b-=1;
			}
			if(a[i+1][1]==1){
				b-=1;
			}
			if(a[i][0]==1&&i%2==0){
				b-=1;
			}
		}
	}
	cout<<b;
	return 0;
}
