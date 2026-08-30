#include<bits/stdc++.h>
using namespace std;
int n;
char d[10];
int ans[10];
int maxans=-1;
bool st=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>d[j];
			if(d[j]=='Y'){
				ans[j]++;
				maxans=(maxans,ans[j]);
			}
		}
	}
	for(int i=1;i<=5;i++){
		if(ans[i]==maxans){
			if(st){
				cout<<i;
				st=0;
			}
			else{
				cout<<","<<i;
			}
		}
	}
	return 0;
}
