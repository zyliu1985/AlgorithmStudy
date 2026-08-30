#include<bits/stdc++.h>
using namespace std;
int g,p;
int a[100010],b[10010],flag,flag1,ans;
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	for(int i=1;i<=p;i++){
		if(flag1==0){
			while(a[i]&&flag==0){
				if(b[a[i]]==0){
					b[a[i]]=1;
					flag=1;
					ans++;
				}else {
					a[i]--;
				}
			}
		}
		if(flag==0) flag1=1;
		flag=0;
	}
	cout<<ans;
	return 0;
}
