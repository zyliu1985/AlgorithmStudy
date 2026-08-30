#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,arr[101],a;
	cin>>c;
	for(int i=0;i<c*2;i++){
		cin>>arr[i];
		if(arr[i]==1){
			a=a+1;
		}
	}
	cout<<a*3<<endl;
	system("pause");
	return 0;
}
