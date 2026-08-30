#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,k,f,m;
	long long a[100010],b[100010],t[100010],k1[100010];
	cin>>k>>m>>n;
	for(int i=1,aa,bb,tii,k;i<=n;i++){
		cin>>aa>>bb>>tii>>k;
		t[i]=tii,k1[i]=k;
		if(aa>bb)
			swap(aa,bb);
		a[i]=aa,b[i]=bb;
	}
	sort(a+1,a+n+1,cmp);
	long long cnt=1,ti[100010];
	sort(t+1,t+n+1);
	cout<<t[n-1];
return 0;
}
