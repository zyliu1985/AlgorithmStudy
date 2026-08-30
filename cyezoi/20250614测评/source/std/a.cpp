#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10],b[10],cnt;
string s; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<5;j++)
			if(s[j]=='Y')a[j]++;
	}
	for(int i=0;i<5;i++)
		if(a[i]>ans){
			ans=a[i];cnt=0;b[++cnt]=i+1;
		}else if(a[i]==ans){
			b[++cnt]=i+1;
		} 
	for(int i=1;i<cnt;i++)cout<<b[i]<<",";	
	cout<<b[cnt];
	return 0;
}  
/*
# P9301 2023J3 ×Ö·û´®

Ä£Äâ

Í°¼ÆÊý 
*/
