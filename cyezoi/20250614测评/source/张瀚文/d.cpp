#include <bits/stdc++.h>
using namespace std;

bool g[100005];
int a[100005];
int main(){
	int G,P;
	bool flag;
	
	cin>>G>>P;
	for(int i=1;i<=P;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=P;i++){	//飞机架数 
		flag=false;
		for(int j=a[i];j>=1;j--){	//从最靠后的停机位往前遍历
			if(g[j]==0){
				g[j]=1;
				flag = true;
				break;
			} 
		} 
		if(!flag){
			cout<<i-1;
			return 0;
		}
	}
	cout<<P;
	return 0;
}
