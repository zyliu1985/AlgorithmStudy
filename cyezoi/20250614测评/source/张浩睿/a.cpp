#include<bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
int main(){
	int n,maxc=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char a;
			cin>>a;
			if(a=='Y') cnt[j]++;
		}
	}
	for(int i=1;i<=5;i++){
		if(cnt[i]==maxc){
			s+=",";
			s+=(char)(i+48);
		}
		if(cnt[i]>maxc){
			maxc=cnt[i];
			s=(char)(i+48);
		}
	}
	cout<<s;
	return 0;
}
/*
5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/
