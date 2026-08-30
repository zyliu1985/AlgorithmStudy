#include<bits/stdc++.h>
using namespace std;


int a[15000];
int G,p,yx,ans=0;
int main(){
	cin>>G>>p;
	for(int i=1;i<=p;i++){
		cin>>yx;
		for(int j=yx;j>=1;j--){
			if(a[j]==0){
				a[j]=1;
				yx=0;
				ans++;
				break;
			}
		}
		if(yx!=0){
			break;
		}
	}
	cout<<ans;
}
