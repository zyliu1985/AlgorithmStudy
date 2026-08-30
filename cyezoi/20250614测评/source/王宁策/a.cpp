#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,c,d,e,f,g,b,zuida;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int a=1;a<=5;a++){
			cin>>b;
			if(a/5==0.2){
				if(b==1){
					c=c+1;
				}
			}
			if(a/5==0.4){
				if(b==1){
					d=d+1;
				}
			}
			if(a/5==0.6){
				if(b==1){
					e=e+1;
				}
			}
			if(a/5==0.8){
				if(b==1){
					f=f+1;
				}
			}
			if(a/5==1){
				if(b==1){
					g=g+1;
				}
			}
		}
	}
	if(c>d){
		zuida=1;
		if(c>e){
			zuida=1;
			if(c>f){
				zuida=1;
				if(c>g){
					zuida=1;
				}
			}
		}
		else{
			if(c=e){
				zuida=1,2,3;
			}
		else{
			zuida=3;
		}
	}
	}
	cout<<zuida<<endl;
	system("pause");
	return 0;
}
