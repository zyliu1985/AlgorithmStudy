#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	char a[100001][5];
	int x[5];
	for(int i=0;i<N;i++){
		for(int o=0;o<5;o++){
			cin>>a[i][o];
			if(a[i][o]=='Y'){
				x[o]++;
			}
		}
	}
	
	int mx=-114514,jie=0,zhu[100001];
	for(int i=0;i<5;i++){
		if(x[i]>=mx){
			mx=x[i];
			zhu[jie]=i+1;
			jie++;
		}
	}
	if(jie!=1){
	    for(int i=0;i<jie-1;i++){
		    cout<<zhu[i]<<',';
	    }
	    cout<<zhu[jie];
    }
    if(jie==1){
    	cout<<zhu[jie];
	}
	return 0;
}
