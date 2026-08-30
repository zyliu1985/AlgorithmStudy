#include<bits/stdc++.h>
using namespace std;
int g,p,mx,f[110000],a[110000],v[110000];
int main(){
	cin>>g>>p;mx=g;
	for(int i=0;i<p;i++){
		cin>>a[i];
		if(i>g){
			mx=min(mx,i-1);break;
		}else{
			for(int j=a[i];j<=g;++j)v[j]++;
			if(v[a[i]]>a[i]){
				cout<<i;return 0;
			}
		}
	}//for(int i=0;i<p;i++)cout<<v[i];
	return 0;
}
