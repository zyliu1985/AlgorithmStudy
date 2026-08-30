#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,minn;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int k=1;k<=n;k++){
		minn=100005;
		for(int i=0;i<=n-k;i++){
			sum=0;
			for(int j=0;j<k/2;j++)	sum+=abs(a[j+i]-a[i+k-j-1]);
			if(sum<minn)	minn=sum;
		}
		cout<<minn<<" ";
	}
	return 0;
}
