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
	for(int i=2;i<=n-1;i++){//取有i个数的数列 
		int minn=1e9+7,sum=0;
		for(int j=1;j+i-1<=n;j++){//从j开始取
			sum=0; 
			l=j;
			r=j+i-1;
			while(l<=r){//sum为这样取的值(su的和),与minn比较 
				int su=0;
				if(a[l]<a[r]) su=a[r]-a[l];
				else su=a[l]-a[r];
				sum+=su;
				l++;
				r--;
			}
			if(sum<minn) minn=sum;	
		}
		cout<<minn<<" ";
	}
	l=1;
	r=n;
	while(l<r){
		int su=0;
		if(a[l]<a[r]) su=a[r]-a[l];
		else su=a[l]-a[r];
		sum+=su;
		l++;
		r--;	
	}
	cout<<sum;
	
	return 0;
}
