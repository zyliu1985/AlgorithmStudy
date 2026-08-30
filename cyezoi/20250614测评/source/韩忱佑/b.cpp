#include<iostream>
using namespace std;

int main(){
	int n,t=0;
	cin>>n;
	int p;
	for(int i=1;i<=2*n;i++){
		cin>>p;
		if(p==1) t+=1;
	}
    cout<<t;
}
