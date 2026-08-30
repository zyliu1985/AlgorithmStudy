#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cc[5]={0},flag=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		if(a=='Y')cc[0]++;
		if(b=='Y')cc[1]++;
		if(c=='Y')cc[2]++;
		if(d=='Y')cc[3]++;
		if(e=='Y')cc[4]++;
	}
	int mx=max(cc[0],max(cc[1],max(cc[2],max(cc[3],cc[4]))));
	for(int i=0;i<=4;i++){
		if(cc[i]==mx){
			if(flag)cout<<",";
			cout<<i+1;
			flag=1;
		}
	}
	return 0;
}
