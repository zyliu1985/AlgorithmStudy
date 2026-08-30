#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int num[11];
string s[100010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxn=0;
	int dou=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
		for(int j=1;j<=5;j++){
			if(s[i][j]=='Y'){
				num[j]++;
			}
		}
	}
	for(int i=1;i<=5;i++){
		maxn=max(maxn,num[i]);
	}
	for(int i=1;i<=5;i++){
		if(num[i]==maxn){
			if(dou==0){
				cout<<i;dou=1;
			}else{
				cout<<","<<i;
			}
		}
	}
	return 0;
}
