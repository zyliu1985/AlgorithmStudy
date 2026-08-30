#include<bits/stdc++.h>
using namespace std;
int n,m,a[30004],b[102];
long long ans,cnt;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++)cin>>b[i];
	if(m==0){
		for(int i=0;i<n;i++){
			if(i%2==0)ans+=a[i];
			else cnt+=a[i];
		}
		if(ans>cnt)cout<<ans;
		else cout<<cnt;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(i%2==0)ans+=a[i];
			else cnt+=a[i];
		}
		if(cnt>ans){
			cnt+=b[0];
			cout<<cnt;
		}else{
			ans+=b[0];
			cout<<ans;
		}
		return 0;
	}
	for(int i=n;i<m+n;i++)a[i]=b[i-n];	
	sort(a,a+m+n);
	int num=m+n;num/=2;
	for(int i=m+n;i>=num;i--)ans+=a[i];
	cout<<ans;
	return 0;
}
