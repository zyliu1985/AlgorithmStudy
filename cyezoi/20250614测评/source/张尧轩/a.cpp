#include<bits/stdc++.h>
using namespace std;
int n,A[10],maxlen=0;
bool flag=0;
char f,b,c,d,e;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c>>d>>e>>f;
		if(b=='Y'){
			A[1]++;	
		}
		if(c=='Y'){
			A[2]++;	
		}
		if(d=='Y'){
			A[3]++;	
		}
		if(e=='Y'){
			A[4]++;	
		}
		if(f=='Y'){
			A[5]++;	
		}
	}
	for(int i=1;i<=5;i++){
		maxlen=max(maxlen,A[i]);
	}
	for(int i=1;i<=5;i++){
		if(A[i]==maxlen){
			if(flag){
				cout<<',';
			}
			flag=1;
			cout<<i;
		}
	}
	return 0;
}
