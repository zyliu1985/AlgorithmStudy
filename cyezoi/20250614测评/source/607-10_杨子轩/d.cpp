#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int G,P;
int g[N];
bool vis[N];
int main(){
	cin>>G>>P;
	for(int i=1;i<=P;i++) cin>>g[i];
	for(int i=1;i<=P;i++){
		bool flag=1;
		for(int j=g[i];j>=1;j--) if(vis[j]==0){
//			cout<<j<<endl;
			vis[j]=1;flag=0;break;
		}
		if(flag){
			cout<<i-1;
			return 0;
		}
	}
	cout<<P;
	return 0;
}
