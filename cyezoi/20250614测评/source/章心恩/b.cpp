#include<bits/stdc++.h>
using namespace std;
int a[2][200005],sum;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				sum+=3;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i+1<n&&a[1][i+1]==1){
			sum-=2;
		}
		if(i%2==0&&a[2][i]==1){
			sum-=2;
		}
	}
	for(int i=0;i<n;i++){
		if(i+1<n&&a[2][i+1]==1){
			sum-=2;
		}
	}
	cout<<sum;
}
