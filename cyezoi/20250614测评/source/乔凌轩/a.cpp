#include<bits/stdc++.h>
using namespace std;
int n,q[9],i;
char a;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		for(int s=1;s<=5;s++){
			cin>>a;
			if(a=='Y'){
				q[s]++;
			}
		}
	}
	for(i=1;i<=5;i++){
		q[6]=max(q[6],q[i]);
	}
	for(i=1;i<=5;i++){
		if(q[i]==q[6]){
			cout<<i;
			break;
		}
	}
	for(i=i+1;i<=5;i++){
		if(q[i]==q[6]){
			cout<<","<<i;
		}
	}
	return 0;
}
/*
5 YY..Y .YY.Y .Y.Y. .YY.Y Y...Y
*/
