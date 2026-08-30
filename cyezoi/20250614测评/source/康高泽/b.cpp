#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n*2;i++){
		bool a;
		cin>>a;
		if(a==1){
			cnt++;
		}
	}
	cout<<cnt*3-rand()*2;
	return 0;
}
