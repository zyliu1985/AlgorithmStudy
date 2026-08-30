#include<bits/stdc++.h>
using namespace std;
int main(){
	int dg,p,g[100005],zy[100005],cnt=0;
	cin>>dg>>p;
	for(int i=1;i<=p;i++){
		cin>>g[i];
	}
	for(int i=1;i<=p;i++){
		int j=g[i];
		while(j>=0&&zy[j]==1){
			j--;
		}
		if(j==0){
			continue;
		}else{
			zy[j]=1;
			cnt++;
		}
	}
	cout<<cnt;
}
