#include<bits/stdc++.h>
using namespace std;

#define ee endl;

long long c,ans=0;
int cc[200100][2];
int xp,yp;

void fnd(int x,int y){
	if(y>2||y<1) return;
	if(x>c||x<1) return;
	if(cc[x][y]==0) return;
	if(x!=xp||y!=yp){
		ans-=2;
	}
	
	xp=x,yp=y;
	if(x%2!=0&&y==1){
		fnd(x+1,y);
		fnd(x,y+1);
	} 
	if(x%2==0){
		fnd(x+1,y);
	} 
	//if(x%2!=0&&y==2){
		
	//	return 1+fnd(x,y-1)+fnd(x+1,y)+fnd(x-1,y);
	//}
	
	cc[x][y]++;
	return;
}

int main(){
	cin>>c;
	for(int j=1;j<=2;j++){
		for(int i=1;i<=c;i++){
			cin>>cc[i][j];
			if(cc[i][j]==1){
				ans+=3;
			}
		}
	}
	for(int j=1;j<=2;j++){
		for(int i=1;i<=c;i++){
			if(cc[i][j]==1){
				xp=i;yp=j;
				fnd(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
