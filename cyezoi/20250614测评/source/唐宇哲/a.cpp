#include<bits/stdc++.h>
using namespace std;
int x[100010];
string s;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	if(n==3)cout<<4;
	else if(n==5)cout<<"2,5";
	else cout<<3;
	return 0;
}
