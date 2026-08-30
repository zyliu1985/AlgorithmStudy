#include<bits/stdc++.h>
using namespace std;
bool a[300000],b[300000];
int main(){
	int c,cnt=0;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];
		cnt+=3*a[i];
	}
	for(int i=1;i<=c;i++){
		cin>>b[i];
		cnt+=3*b[i];
	}
	
	a[c+1]=b[c+1]=0;
	int t=0;
	for(int i=1;i<=c+1;i++){
		if(!a[i]){
			if(t>1){
				cnt-=2*t-2;
			}
			t=0;
		}
		else{
			t++;
		}
	}
	t=0;
	for(int i=1;i<=c+1;i++){
		if(!b[i]){
			if(t>1){
				cnt-=2*t-2;
			}
			t=0;
		}
		else{
			t++;
		}
	}
	
	for(int i=1;i<=c;i+=2){
		if(a[i]&&b[i]){
			cnt-=2;
		}
	}
	cout<<cnt;
	return 0;
}
/*
7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/
