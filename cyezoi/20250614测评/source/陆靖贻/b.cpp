#include<bits/stdc++.h>
using namespace std;
int c,ans;
int main(){
	cin>>c;
	for(int i=0;i<2*c;i++){
		int x;
		cin>>x;
		ans+=x;
	}
	cout<<3*ans;
	return 0;
}
