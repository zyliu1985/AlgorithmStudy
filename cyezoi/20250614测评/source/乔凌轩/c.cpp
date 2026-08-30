#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5010],cf[5010],flag,ans,mn=0x7f7f7f;
int main(){
	cin>>n;
	cf[5009]=0x7f7f7f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
		cf[5009]=min(cf[5009],abs(cf[i]));
	}
	cout<<0;
	for(int t=2;t<=n;t++){
		
		if(t==2){
			cout<<' '<<abs(cf[5009]);
			continue;
		}
		if(t==3){
			for(int i=1;i<=n-2;i++){
				mn=min(mn,abs(cf[i]+cf[i+1]));
			}
			cout<<' '<<mn;
			continue;
		}
		ans=0x7f7f7f,flag=0;
		for(int i=1;i+t-1<=n;i++){
			flag=0;
			for(int s=1;s<=t/2;s++){
				flag+=abs(a[i+s-1]-a[t+s-i-1]);
			}
			ans=min(ans,flag);	
		}
		flag=0;
		cout<<' '<<ans;
	}
	return 0;

}
/*
7 3 1 4 1 5 9 2
4 1 3 5 6
*/
