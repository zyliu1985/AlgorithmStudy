#include<bits/stdc++.h>
using namespace std;

char a[105000];
char b[105000];
char c[105000];
char d[105000];
char e[105000];
int s[10]={0};
int n,mx=0,l;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
		if(a[i]=='Y'){
			s[1]++;
		}
		if(b[i]=='Y'){
			s[2]++;
		}
		if(c[i]=='Y'){
			s[3]++;
		}
		if(d[i]=='Y'){
			s[4]++;
		}
		if(e[i]=='Y'){
			s[5]++;
		}
	}
	for(int i=1;i<=5;i++){
		if(s[i]>mx){
			mx=s[i];
			l=i;
			s[i]=0;
		}
	}
	cout<<l;
	l=0;
	for(int i=1;i<=5;i++){
		if(s[i]==mx){
			l=i;
			cout<<','<<l;
			l=0;
		}
	}
}
