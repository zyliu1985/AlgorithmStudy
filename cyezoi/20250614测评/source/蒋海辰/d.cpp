#include<bits/stdc++.h>
using namespace std;
int main(){
	int g,p,s[100001],jie[100001],ans,jie1;
	cin>>g>>p;//4 6
	for(int i=0;i<p;i++){
		cin>>s[i];//2 2 3 3 4 4
	}
	for(int i=0;i<p;i++){
		jie1=ans;
		for(int o=s[i];o>0;o--){
			if(jie[o-1]==0){ 
				jie[o-1]++;
				ans++;
				break;
			}
	    }
	    if(jie1==ans){
		    break;
		}
	}
	cout<<ans;
	return 0;
}
