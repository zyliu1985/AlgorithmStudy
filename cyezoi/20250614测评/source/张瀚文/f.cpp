#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
} 

int a[3500];
int main(){
	int m,n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=n+1;i<=n+m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m+n,cmp);
	int k=(m+n+1)/2;
	for(int i=1;i<=k;i++){
		sum+=a[i];
	}
	cout<<sum;
}
