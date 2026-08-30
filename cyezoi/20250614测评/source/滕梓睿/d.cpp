#include<bits/stdc++.h>
using namespace std;
int g,p;
int a[100005];
int main(){
	cin>>g>>p;
	int ans=0;
	for(int i=0;i<p;i++){
		int x;
		cin>>x;
		bool flag=true;
		for(int j=x;j>=1;j--){
			if(a[j]==0){
				a[j]=1;
				ans++;
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<ans;
			return 0;
		} 
	}
	cout<<ans;
	return 0;
}
