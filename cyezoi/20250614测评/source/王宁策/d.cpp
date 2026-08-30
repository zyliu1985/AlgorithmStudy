#include <bits/stdc++.h>
using namespace std;
int main(){
	int g,p,arr[101],a;
	cin>>g>>p;
	for(int i=0;i<p;i++){
		cin>>arr[i];
		if(arr[i]>g){
			arr[i]=arr[i]-g;
		}
	}
	for(int i=0;i<p;i++){
		if(arr[i]!=arr[i+1]){
			a=a+1;
		}
	}
	cout<<a<<endl;
	system("pause");
	return 0;
}
