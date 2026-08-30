#include<bits/stdc++.h>
using namespace std;
int a[3005],b[105],c[3105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m,n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	cin>>m;
	if(m==0){
		for(int i=1;i<=n;i++){
			if(i%2==1){
				ans+=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		cin>>b[i];
//		c[i+n]==b[i];
//	}
//	sort(c,c+n+m,cmp);
//	sort(b,b+m);
//	
	return 0;
}
