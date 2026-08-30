#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010]={0};
int main(){
	int g,p,ans=0;
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	for(int i=1;i<=g;i++){
		b[i]=i;
	}
	for(int i=1;i<=p;i++){
		if(b[a[i]]!=0){
			ans++;
			b[a[i]]=0;
		}else{
			for(int j=1;j<a[i];j++){
				if(b[a[i]-j]!=0){
					ans++;
					b[a[i]-j]=0;
				}else if(j==a[i]-1){
					cout<<ans;
					return 0;
				}
			}
		}	
	}
	cout<<ans;
	return 0;
}
