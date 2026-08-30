#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++){
			char x;cin>>x;
			if(x=='Y') a[j]++;
		}
	int maxx=-1,l=0;
	for(int i=1;i<=5;i++)
		if(a[i]>maxx) l=i,maxx=a[i];
	int len=1;
	for(int i=1;i<=5;i++){
		if(a[i]==maxx&&len==1){
			cout<<i;len++;
		}
		else if(a[i]==maxx&& len!=1){
			cout<<","<<i;
		}
	}
}
