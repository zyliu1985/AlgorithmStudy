#include<bits/stdc++.h>
using namespace std;
int n,minn,sum;
int a[5005],l,r; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0<<" ";
	for(int i=2;i<=n-1;i++){//i 
		int minn=1e9+8,sum=0;
		for(int j=1;j<=n-i+1;j++){//起始点 
			sum=0;
			l=j;
			r=j+i-1; //起始点开始后i-1个
			while(l<=r){
				int su=0;
				if(a[l]<a[r])
				su=a[r]-a[l];
				else su=a[l]-a[r];
				sum+=su;
				l++;
				r--;
			}
			if(sum<minn){
				minn=sum;
			}
		}
		cout<<minn<<" ";
	}
	l=1;
	r=n;
	while(l<r){
		int su=0;if(a[l]<a[r]) su=a[r]-a[l];
		else su=a[l]-a[r];
		sum+=su;
		l++;
		r--; 
	}
	cout<<sum;
	return 0;
}
