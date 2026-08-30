#include <bits/stdc++.h>
using namespace std;
int n;
char s;
int b[10];
int main( ){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=1;j<=5;j++){
			cin>>s;
			if(s=='Y')
				b[j]++;
		}
	int maxn=0;
	for(int i=1;i<=5;i++)
		maxn=max(maxn,b[i]);
	int len=1;
	for(len=1;len<=5;len++)
		if(b[len]==maxn){
			cout<<len;
			break;
		}
	for(int i=len+1;i<=5;i++)
		if(b[i]==maxn)
			cout<<","<<i;
	return 0;
}
