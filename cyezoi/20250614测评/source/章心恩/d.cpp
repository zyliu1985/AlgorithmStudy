#include<bits/stdc++.h>
using namespace std;
int g[100005];
bool f[100005];
int main(){
	int g,p;
	cin>>g>>p;
	for(int i=0;i<p;i++){
		int t;
		cin>>t;
		while(f[t]==true&&t>0){
			t--;
		}
		if(t==0){
			cout<<i;
			return 0;
		}else{
			f[t]=true;
		}
	}
	cout<<p;
}
