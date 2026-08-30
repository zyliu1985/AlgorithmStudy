#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int a[200005][2],d;
void dfs(int b,int c){
	if(!a[b][c]&&b>d){
		return;
	}
	cnt--;
	cnt+=3;
	a[b][c]=0;
	dfs(b+1,c);
	if(b%2==0&&c==0){
		dfs(b,c+1);
	}
	return;
}
int main(){
	int d;

	cin>>d;
	for(int i=0;i<d;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<d;i++){
		for(int j=0;j<2;j++){
			if(a[i][j]){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout<<cnt;
}
