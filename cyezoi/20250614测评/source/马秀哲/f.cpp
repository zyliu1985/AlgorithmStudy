#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nm{
int l,r;
};
int a[152100],b[152100];
nm c[152100];
int d[152100];
bool cmp(nm x,nm y){
	return x.l >y.l ;
}
signed main(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i].l=a[i];
		c[i].r=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
		c[n+i].l=b[i];
		c[n+i].r=n+i;
	}
	int dd=n+m;
	int cnt=0;
	sort(c+1,c+dd+1,cmp);
	dd=(dd+1)/2;
	for(int i=1;i<=dd;i++){
		if(c[i].r<=n){
			d[++cnt]=c[i].r;
		}
	}
	int ans=0;
	sort(d+1,d+cnt+1);
	int arr=1;
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(d[arr]==i){
			arr+=1;
			if(i%2==0&&flag==false){
				ans+=2;
				if(arr==cnt+1){
					ans-=1;
				}
			}
			if(i%2==1){
				flag=false;
				if(arr==cnt+1){
					ans-=1;
				}
			}
		}
	}
	int sss=dd+m-ans;
	int yyy=0;
	for(int i=1;i<=sss;i++){
		yyy+=c[i].l;
	}
	cout<<yyy;
	return 0;
}
