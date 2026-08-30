#include<bits/stdc++.h>
using namespace std;
bool b[100005];
int g[100005];
int main(){
	int G,P,ans=0;
	cin>>G>>P;
	for(int i=1;i<=P;i++){
		cin>>g[i];
	}
	for(int i=1;i<=P;i++){
		bool f=0;
		for(int j=g[i];j>=1;j--){
			if(b[j]==0){
				b[j]=1;
				f=1;
				ans++;
				break;
			}
		}
		if(f==0){
			cout<<ans;
			return 0;
		}
	}
	cout<<P;
	return 0;
}
