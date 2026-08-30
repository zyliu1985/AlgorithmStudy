#include<bits/stdc++.h>
using namespace std;
int n,a[2000005][2],re=0,sides=0;
int main(){
	//freopen("data.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		if(a[i][0]==1){
			sides+=3;
			if(a[i-1][0]==1) re+=2;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		if(a[i][1]==1){
			sides+=3;
			if(a[i-1][1]==1) re+=2;
			if(i%2==1 and a[i][0]==1) re+=2;
		}
	}
	cout<<sides-re<<endl;
	return 0;
}
