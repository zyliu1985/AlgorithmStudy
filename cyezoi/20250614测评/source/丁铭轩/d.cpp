#include<bits/stdc++.h>
using namespace std;

int g,p,ans=0;
int a[100010];
bool k[100010]={0};

bool ntm(int x){
	if(x==0) return 0; 
	if(k[x]==1) ntm(x-1);
	else{
		k[x]=1;
		return 1;
	}
}
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++) cin>>a[i];
	for(int i=1;i<=p;i++){
		if(ntm(a[i])) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
