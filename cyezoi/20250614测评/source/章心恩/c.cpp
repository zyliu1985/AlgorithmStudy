#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i+2]=300000000;
	}
	for(int i=0;i<n;i++){
		int r=i+1,l=i-1,s=0;
		while(r<n&&l>=0){
			s+=max(a[r],a[l])-min(a[r],a[l]);
			if(s<b[r-l+1]){
				b[r-l+1]=s;
			}
			r++;
			l--;
		}
	}
	for(int i=0;i<n-1;i++){
		int r=i+1,l=i,s=0;
		while(r<n&&l>=0){
			s+=max(a[r],a[l])-min(a[r],a[l]);
			if(s<b[r-l+1]){
				b[r-l+1]=s;
			}
			r++;
			l--;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
}
