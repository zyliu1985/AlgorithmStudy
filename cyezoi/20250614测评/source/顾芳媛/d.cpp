#include<bits/stdc++.h>
using namespace std;
int g,p,l[100010];
bool d[100010];
int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>l[i];
	}
	int ans=0;
	for(int i=1;i<=p;i++){
		if(d[l[i]]!=1){
			d[l[i]]=1;
			ans++;
		}
		else{
			for(int j=l[i];j>=0;j--){
				if(j==0){
					cout<<ans;
					return 0;
				}
				if(d[j]!=1){
					d[j]=1;
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
