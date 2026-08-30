#include<bits/stdc++.h>
using namespace std;
int g,p;
int a[1000005];
long long bcj(int x){
	if(x<=0){
		return 0;
	}
	if(x==a[x]){
		return x;
	}
	a[x]=bcj(a[x]);
	return a[x];
}
int main(){
	//freopen("data.in","r",stdin);
	cin>>g>>p;
	for(int i=0;i<=g;i++){
		a[i]=i;
	}
	int ans=0;
	for(p;p>0;p--){
		int x;
		cin>>x;
		if(x==a[x]){
			ans++;
			a[x]=x-1;
		}
		else{
			long long b=bcj(x);
			if(b==0){
				cout<<ans;
				return 0;
			}
			else{
				ans++;
				a[b]=a[b]-1;
			}
		}
		//cout<<"                  "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

