#include<bits/stdc++.h>
using namespace std;
int n;
int a[6];
int main(){
	cin>>n;
	for(int i=1;i<=5;i++){
		a[i]=0;
	}
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<5;j++){
			if(s[j]=='Y'){
				a[j+1]++;
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=5;i++){
		maxx=max(maxx,a[i]);
	}
	int flag=0;
	for(int i=1;i<=5;i++){
		if(a[i]==maxx){
			flag++;
			if(flag==1){
				cout<<i;
			}
			else cout<<","<<i;
		}
	}
	return 0;
}
//3 YY.Y. ...Y. .YYY.
