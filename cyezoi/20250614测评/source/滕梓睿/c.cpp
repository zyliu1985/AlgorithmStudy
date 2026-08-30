#include<bits/stdc++.h>
using namespace std;
int n;
int h[5005];
int abs(int a){
	if(a<0)return -a;
	else return a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		h[i]+=h[i-1];
	}
	for(int i=1;i<=n;i++){
		int ans=0x3f3f3f3f;
		for(int j=1;j+i-1<=n;j++){
			int x=0;
			if(i%2==1){
				x=abs(abs(h[j+i/2]-h[j-1])-abs(h[j+i-1]-h[j+i/2-1]));
			}
			else{
				x=abs(abs(h[j+i/2-1]-h[j-1])-abs(h[j+i-1]-h[j+i/2-1]));
			}
			ans=min(x,ans);
		}
		cout<<ans<<" ";
	}
	return 0;
}
