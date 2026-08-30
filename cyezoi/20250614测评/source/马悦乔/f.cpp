#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a<b;
}
int n,m;
int a[3110],b[105];
int f(int num) {
	int cnt=0;
	for(int i=0; i<=num; i+=2) {
		cnt+=a[i];
	}
	return cnt;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	cin>>m;
	for(int j=0; j<m; j++)cin>>b[j];
	sort(b,b+m,cmp);
	for(int i=0; i<m; i++) {
		int change=0,h;
		for(int j=0; j<n+i+1; j++) {
			for(int z=n-1+i; z>=j; z--) {
				a[z+1]=a[z];
			}
			a[j]=b[i];
			if(f(n-1+i)>change) {
				change=f(n-1+i);
				h=j;
			}
			for(int z=j; z<n+i; z++) {
				a[z]=a[z+1];
			}
		}
		for(int z=n-1+i; z>=h; z--) {
			a[z+1]=a[z];
		}
		a[h]=b[i];
	}
	cout<<f(n+m-1);
	return 0;
}
