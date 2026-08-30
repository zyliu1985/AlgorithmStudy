#include<bits/stdc++.h>
using namespace std;
int n,a[6],ans[6],mx,l;char tmp;
int main(){
	cin>>n;
	for(int j=0;j<n;j++){
		for(int i=0;i<=5;i++){
			tmp=getchar();
			a[i]+=(tmp=='Y');
		}
	}
	
	for(int i=0;i<=5;i++){
		if(a[i]>a[mx])mx=i;
	}
	for(int i=0;i<=5;i++){
		if(a[i]==a[mx])ans[l++]=i;
	}
	for(int i=0;i<l-1;i++){
		cout<<ans[i]<<",";
	}cout<<ans[l-1];
	return 0;
}
