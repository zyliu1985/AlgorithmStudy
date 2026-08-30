#include<bits/stdc++.h>
using namespace std;
int n,mans,id[10005],l;
bool a[10005][10005];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			char x;
			cin>>x;
			if(x=='Y') a[i][j]=true;
			else a[i][j]=false;
		}
	}
	for(int i=0;i<5;i++){
		int k=0;
		for(int j=0;j<n;j++){
			if(a[j][i]) k++;
		}
		if(k==mans){
			l++;
			id[l]=i;
			
		}
		else if(mans<k){
			l=0;
			id[l]=i;
			mans=k;
		}
	}
	for(int i=0;i<=l-1;i++){
		cout<<id[i]+1<<',';
	}
	cout<<id[l]+1;
	
	return 0;
}

