#include<bits/stdc++.h>
using namespace std;
int a[100005],num[100005];
int main(){
	int g,p;
	cin>>g>>p;
	for(int i=0;i<p;i++){
		cin>>a[i];
		for(int j=a[i];j<g;j++){
			num[j]++;
			if(num[j]>j){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<g;
	return 0;
}
