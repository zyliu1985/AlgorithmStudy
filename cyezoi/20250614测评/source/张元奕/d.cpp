#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int G,p,ans=0;
int a[MAXN]={0},ap[MAXN]={0};
bool check(int m){
	for(int i=m-1;i>=0;i--){
		if(a[i]!=1){
			a[i]=1;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>G>>p;
	for(int i=0;i<p;i++){
		cin>>ap[i];
		if(check(ap[i])){
			ans++;
		}
		else break;
	}
	if(ans>G)	cout<<G;
	else	cout<<ans;
	return 0; 
} 
