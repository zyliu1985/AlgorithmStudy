#include<bits/stdc++.h>
using namespace std;
string a[100000];
int b[5];
int main(){
	int n,d=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<5;i++){
		int c=0;
		for(int j=0;j<n;j++){
			if(a[j][i]=='Y'){
				c++;
			}
		}
		if(c==d){
			for(int j=0;j<5;j++){
				if(b[j]==0){
					b[j]=i;
					break;
				}
			}
		}
		if(c>d){
			d=c;
			for(int j=0;j<5;j++){
				if(b[j]==0){
					break;
				}
				b[j]=0;
			}
			b[0]=i;
		}
	}
	for(int i=0;i<5;i++){
		cout<<b[i]+1;
		if(b[i+1]!=0){
			cout<<",";
		}
		else{
			break;
		}
	}
	return 0;
}
