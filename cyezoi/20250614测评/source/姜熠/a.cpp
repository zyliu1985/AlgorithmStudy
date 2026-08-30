#include<bits/stdc++.h>
using namespace std;
int day[6];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char x;
			cin>>x;
			if(x=='Y'){
				day[j]++;
			}
		}
	}
	int maxn=-1;
	for(int i=1;i<=5;i++){
		maxn=max(maxn,day[i]);
	}
	int day2[10];
	int cur=0;
	for(int i=1;i<=5;i++){
		if(day[i]==maxn){
			cur++;
			day2[cur]=i;
		}
	}
	for(int i=1;i<=cur-1;i++){
		cout<<day2[i]<<",";
	}
	cout<<day2[cur];
	return 0;
}
