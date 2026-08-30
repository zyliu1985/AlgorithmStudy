#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int h[n+5];
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int len=1;len<=n;len++){
		int l=1,r=len,minn=0x3f3f3f3f,sum=0;
		while(r<=n){
			for(int i=0;i<len;i++){
				sum+=fabs(h[l+i]-h[r-i]);
			}
			if(sum<minn)
				minn=sum;
		}
		cout<<minn<<" ";
	}
	return 0;
}
