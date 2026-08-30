#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long cnt=0,book[10010],n,a[10010],ans=0;
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(i==1)
				book[j]=a[j];
			if(a[j]==1)
				ans++;
			if(j>=2&&a[j]==1&&a[j-1]==1){
				cnt++;
			}
			if(i==2)
				if(book[j]==1&&a[j]==1)
					cnt++;
		}
	}
	cnt*=2;
	cout<<abs(ans*3-cnt);
return 0;
}
