#include<bits/stdc++.h>
using namespace std;
int G,P;
int g[100010];
bool port[100010];
int ans;
int main(){
	cin>>G>>P;
	for(int i=1;i<=P;i++){
		cin>>g[i];
	}
	int i=1;
	while(i<=P){
		int j=g[i];
		while(port[j]&&j>=1){
			j--;
		}
		if(j==0){
			break;
		}
		port[j]=1;
		i++;
		ans++;
	}
	cout<<ans;
	return 0;
}
