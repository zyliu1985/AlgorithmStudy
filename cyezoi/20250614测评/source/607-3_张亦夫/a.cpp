#include<bits/stdc++.h>
using namespace std;
int n,cnt[105],mx;
string s;
bool first=true;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=0;j<s.size();++j){
			if(s[j]=='Y') cnt[j+1]++;
		}
	}
	for(int i=1;i<=5;++i) mx=max(mx,cnt[i]);
	for(int i=1;i<=5;++i){
		if(cnt[i]==mx){
			if(first) first=false;
			else cout<<",";
			cout<<i;
		}
	}
	return 0;
}
