#include <bits/stdc++.h>
using namespace std;
int n;
int h[5010];
int main( ){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>h[i];
	cout<<"0";
	for(int i=2;i<=n;i++){
		int minn=100000000;
		for(int j=0;j+i<=n;j++){
			int sum=0;
			for(int k=j;k<=j+(i/2);k++){
				sum+=abs(h[k]-h[j+i-1-(k-j)]);
			}
			minn=min(minn,sum);
		}
		cout<<" "<<minn;
	}
	return 0;
}
