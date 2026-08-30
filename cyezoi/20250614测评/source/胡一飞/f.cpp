#include<bits/stdc++.h>
using namespace std;

int n,m;
int sum1,sum2,sum3,sum4;

int main(){

	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(i%2==1) sum1+=t;
		else sum2+=t;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		if(i%2==1) sum3+=t;
		else sum4+=t;
	}
	int maxx=max(sum1+sum4,sum2+sum3);
	cout<<maxx;
	
	return 0;
}
