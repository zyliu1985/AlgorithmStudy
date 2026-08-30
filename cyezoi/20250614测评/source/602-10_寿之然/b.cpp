#include <bits/stdc++.h>
using namespace std;
int a[5][200010];
int vis[3][200010];
int n;
int sum;
int main( ){

	cin>>n;
	for(int i=1;i<=2;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	sum=0;
	for(int i=1;i<=2;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==1){
				sum+=3-(a[i][j+1]+a[i][j-1]);
				if(j%2==0)
					sum-=(a[i-1][j]+a[i+1][j]);
			}
	cout<<sum;
	return 0;
}
