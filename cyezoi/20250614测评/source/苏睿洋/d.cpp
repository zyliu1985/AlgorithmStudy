#include<bits/stdc++.h>
using namespace std;

int g,p,f,a[100010];

int main(){
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		cin>>f;
		while(a[f]!=0 && f>=0) f--;
		if(f==0){
			cout<<i-1;
			return 0;
		}
		else a[f]=1;
	}
	cout<<p;
	return 0;
}
