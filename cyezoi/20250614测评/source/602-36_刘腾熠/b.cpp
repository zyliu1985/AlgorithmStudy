#include<bits/stdc++.h>
using namespace std;
long long ans;
int c;
int a[200005],b[200005];
int main(){
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];if(a[i]==0)a[i]=2;
	}
	for(int i=1;i<=c;i++){
		cin>>b[i];if(b[i]==0)b[i]=2;	
	}
	for(int i=1;i<=c;i++){
		if(a[i]==2)continue;
		if(a[i]==0)continue;
		int c=3;
		if(a[i-1]==1)c--;
		if(b[i]==1)c--;
		if(a[i+1]==1)c--;
		ans+=c;
	}
	for(int i=1;i<=c;i++){
		if(b[i]==2)continue;
		if(b[i]==0)continue;
		int c=3;
		if(b[i-1]==1)c--;
		if(a[i]==1)c--;
		if(b[i+1]==1)c--;
		ans+=c;
	}
	for(int i=1;i<=c;i++){
		if(i%2==0&&a[i]==1&&b[i]==1)ans+=2;
	}
	cout<<ans;
	return 0;
}
