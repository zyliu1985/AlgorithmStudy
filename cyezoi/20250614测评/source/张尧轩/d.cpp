#include<bits/stdc++.h>
using namespace std;
int C[100005],D[100005],n,g,ans=0;
int main(){
	cin>>g>>n;
	for(int i=1;i<=n;i++){
		cin>>C[i];
	}
	for(int i=1;i<=n;i++){
		while(D[C[i]]==1){
			C[i]--;
			if(C[i]==0){
				cout<<ans;
				return 0;
			}
		}
		D[C[i]]=1;
		ans++;
	}
	cout<<ans;
	return 0;
}
