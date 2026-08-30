#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int a[6];
int maxn;
bool flag=1;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<5;j++){
			if(s[j]=='Y'){
				a[j+1]++;
			}
		}
	}
	for(int i=1;i<=5;i++){
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=5;i++){
		if(a[i]==maxn){
			if(!flag){
				cout<<",";
			}
			cout<<i;
			flag=0;
		}
	}
	return 0;
}
