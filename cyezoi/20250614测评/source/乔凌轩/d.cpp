#include<bits/stdc++.h>
using namespace std;// 1 9 1
long long g,n,f[100010];
bool check(long long a){
	long long mx=0,c[100010]={0};
	for(int i=1;i<=a;i++){
		mx=max(mx,f[i]);
	}
	for(int i=1;i<=a;i++){
		c[f[i]]++;
	}
	for(int i=1;i<=mx;i++){
		c[i]=c[i-1]+c[i];
	}
	for(int i=1;i<=mx;i++){
		if(c[i]>i){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin>>g>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==1){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
/*
4 3 4 1 1
4 6 2 2 3 3 4 4
*/
