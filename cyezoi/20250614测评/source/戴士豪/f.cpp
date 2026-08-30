#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int w;
}a[3010];

int n,m,b[110],t[4010],ans=0,vis[3010];

bool cmp(node x,node y){
	return x.x>y.x;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].w=i;
		t[i]=a[i].x;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
		t[n+i]=b[i];
	}
	if(m==0){
		int cnt=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int f=1;
			for(int j=i-1;j>=1;j--){
				if(abs(a[j].w-a[i].w)==1 && vis[j]==1){
					f=0;
					break;
				}
			}
			if(f==1){
				cnt++;
				vis[i]=1;
				ans+=a[i].x;
			}
			if(n%2==1){
				if(cnt==n/2+1){
					break;
				}
			}
			else{
				if(cnt==n/2){
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		int cnt=0,fh=1;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int f=1,c=0;
			for(int j=i-1;j>=1;j--){
				if(abs(a[j].w-a[i].w)==1 && vis[j]==1){
					if(fh==1){
						c++;
					}
					f=0;
				}
			}
			if(f==0 && fh==1 && c==1 && a[i].x>b[1]){
				cnt++;
				vis[i]=1;
				ans+=a[i].x;
				fh==0;
			}
			if(f==1){
				cnt++;
				if(n%2==1 && cnt==n/2+1 && a[i].x<b[1] && fh==1){
					ans+=b[1];
				}
				else if(n%2==0 && cnt==n/2 && a[i].x<b[1] && fh==1){
					ans+=b[1];
				}
				else{
					vis[i]=1;
					ans+=a[i].x;
				}
			}
			if(n%2==1){
				if(cnt==n/2+1){
					break;
				}
			}
			else{
				if(cnt==n/2){
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	int l=m+n;
	sort(t+1,t+l+1);
	for(int i=l;i>=l/2+1;i--){
		ans+=t[i];
	}
	cout<<ans;
	return 0;
}
