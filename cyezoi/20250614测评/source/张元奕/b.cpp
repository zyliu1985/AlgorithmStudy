#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005;
int c,sum=0,ans=0;
int a[2][MAXN]={0},is[2][MAXN]={0};
void check(int x,int y){
	if(is[x][y])	return;
	is[x][y]=1;
	if(a[x][y]){
		sum++;
		if(x){
			if(x>0)	check(x-1,y);
			check(x+1,y);
		}
		else{
			if(x>0)	check(x-1,y);
			check(x+1,y);
			check(x,y+1);
		}
	}
	return;
}
int main(){
	cin>>c;
	for(int i=0;i<2;i++)	for(int j=0;j<c;j++)	cin>>a[i][j];
	for(int i=0;i<2;i++){
		for(int j=0;j<c;j++){
			sum=0;
			check(i,j);
			if(sum==2*c){
				cout<<c/2*2+4;
				return 0;
			}
			if(sum>0)	ans+=(sum+2);
			
		}
	}
	cout<<ans;
	return 0;
}
