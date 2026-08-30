#include<bits/stdc++.h>
using namespace std;

#define ee endl;

long long g,p,x,ans=0;
bool pl[100100]={};

int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>x;
		for(int j=x;j>=1;j--){
			if(pl[j]==0){
				pl[j]=1;
				ans+=1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
