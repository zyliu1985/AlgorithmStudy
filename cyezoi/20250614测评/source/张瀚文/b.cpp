#include <bits/stdc++.h>
using namespace std;
bool a[200005],b[200005];
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(a[i-1]==0) sum++;
			if(a[i+1]==0) sum++;
			if(i%2==0 || b[i]==0) sum++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			if(b[i-1]==0) sum++;
			if(b[i+1]==0) sum++;
			if(i%2==0 || a[i]==0) sum++;
		}
	}
	cout<<sum;
	return 0;
}
