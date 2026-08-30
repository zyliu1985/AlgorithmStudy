#include<bits/stdc++.h>
using namespace std;
string s;
bool f=false;
int a[6],n,m=-1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int i=0;i<5;i++){
			if(s[i]=='Y')a[i+1]++;
		}
	}
	for(int i=1;i<=5;i++){
		m=max(m,a[i]);
	}
	for(int i=1;i<=5;i++){
		if(a[i]==m&&f==false){
			f=true;
			cout<<i;
		}
		else if(a[i]==m)cout<<","<<i;
	}
	return 0;
}
