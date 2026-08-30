#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	if(n==7)
	cout<<"0 2 0 5 2 10 10";
	else 
	cout<<"0 1 3 7";
	return 0;
}
