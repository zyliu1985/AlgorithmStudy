#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		s="?"+s;
		for(int i=1;i<s.size();++i)
			if(s[i]=='Y')	a[i]++;
	}
	int maxn=0;
	bool flag=0;
	for(int i=1;i<6;++i)
		maxn=max(maxn,a[i]);
	for(int i=1;i<6;++i)
		if(a[i]==maxn){
			if(flag)	cout<<','<<i;
			else{
				cout<<i;
				flag=1;
			}
		}
	return 0;
}
