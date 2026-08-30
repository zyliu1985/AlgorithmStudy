#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt[10],mx=-1;
char c;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='Y')mx=max(mx,++cnt[j]);
		}
	}
	bool isf=1;
	for(int i=1;i<=5;i++){
		if(cnt[i]==mx){
			if(!isf) cout<<',';
			isf=0;
			cout<<i;
		}
	}
	return 0;
}
