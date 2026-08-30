#include<iostream>
using namespace std;

int full[100005];

int main(){
	int G,P,t=0;
	cin>>G>>P;
	int g[P+5];
	for(int i=1;i<=P;i++){
		cin>>g[i];
	}
	
	//Begin to arrive!
	for(int i=1;i<=P;i++){
		int beginG = 1;
		for(int m=i+1;m<=P;m++){
		    if(g[m]<g[i]&&g[m]>=beginG){
			    beginG=g[m]+1;
	    	}
	    }
	    //cout<<beginG<<" "<<g[i]<<" ";
		for(int j=beginG;j<=g[i];j++){
			if(full[j]==0){
				full[j]=1;
				t+=1;
				//cout<<j<<" "<<t<<endl;
				break;
			} else if(full[j]==1&&j==g[i]){
				cout<<t;
				return 0;
			}
		}
	}
	cout<<t;
	return 0;
}
