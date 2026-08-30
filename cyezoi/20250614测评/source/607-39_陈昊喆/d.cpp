#include<bits/stdc++.h>
using namespace std;
int g,p;
bool a[100010];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>g>>p;
	for(int i=1;i<=p;i++){
		int rq;cin>>rq;
		bool flag=true;
		for(int j=rq;j>=1;j--){
			if(!a[j]){
				a[j] = true;
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<i-1;
			return 0;
		}
	}
	cout<<p;
	return 0;
}
/*
4 3
4 1 1

4 6
2 2 3 3 4 4
*/
