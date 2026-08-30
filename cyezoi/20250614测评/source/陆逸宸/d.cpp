#include <bits/stdc++.h>
using namespace std;
long long g,p,ans,a[100010];
bool w[100010];
int main(){
	cin>>g>>p;
	for(int i=0;i<p;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<p;i++){
		bool f=1;
		for(int j=a[i];j>=1;j--){
			if(!w[j]){
				w[j]=1;
				f=0;
				break;
			}
		}
		if(f){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
