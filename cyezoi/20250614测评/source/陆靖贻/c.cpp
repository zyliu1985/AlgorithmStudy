#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005];
int f(int ln){
	int ans=100005;
	for(int i=0;i<n-ln;i++){
		int le=i,ri=i+ln-1,x;
		while(le==ri or le>ri){
			x+=abs(a[le]-a[ri]);
			le++;
			ri--;
		}
		ans=min(x,ans);
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		s[l]=f(l);
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++) cout<<s[i];
	return 0;
}
