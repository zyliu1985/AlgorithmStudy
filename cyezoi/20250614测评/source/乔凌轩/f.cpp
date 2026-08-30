#include<bits/stdc++.h>
using namespace std;
int n,m,he,a[3110];
long long ans;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cin>>m;
	if(m!=0) {
		he=n+m;
		for(int i=n+1; i<=he; i++) {
			cin>>a[i];
		}
		sort(a+1,a+he+1);
		for(int i=he; i>=(he+1)/2+1; i--) {
			ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==0) { //Ææ¹ÖµÄ01±³°ü
		he=n+m;
		for(int i=n+1; i<=he; i++) {
			cin>>a[i];
		}
		sort(a+1,a+he+1);
		for(int i=he; i>=(he+1)/2+1; i--) {
			ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
}
/*
5 10 12 6 14 7 3 1 8 2
*/
