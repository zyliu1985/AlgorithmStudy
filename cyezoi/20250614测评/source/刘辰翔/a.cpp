#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt[10];
char a[100010][7];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
			if(a[i][j]=='Y'){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=5;i++){
		if(cnt[i]>=cnt[ans]){
			ans=i;
		}
	}
	for(int i=1;i<=5;i++){
		if(cnt[i]==cnt[ans]){
			cout<<i;
			if(i!=ans)cout<<",";
		}
	}
}
