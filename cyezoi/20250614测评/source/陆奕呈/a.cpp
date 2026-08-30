#include<bits/stdc++.h>
using namespace std;
bool a[100005][7];
int c[7];
int main(){
	int n;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>b;
			if(b=='Y'){
				a[i][j]=true;
			}else{
				a[i][j]=false;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			if(a[i][j]){
				c[j]++;
			}
		}
	}
	int ans=1;
	for(int i=2;i<=5;i++){
		if(c[i]>=c[ans]){
			ans=i;
		}
	}
	for(int i=1;i<ans;i++){
		if(c[i]==c[ans]){
			cout<<i<<",";
		}
	}
	cout<<ans;
}
