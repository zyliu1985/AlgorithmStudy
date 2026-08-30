#include<bits/stdc++.h>
using namespace std;
int s1[200020],s2[200020];
int n[200020]={0};
int pd(int k){
	if(s1[k]==1&&s2[k]==1){
		n[k]=n[k]+2;
		s1[k]=0;
		s2[k]=0;
		n[k]=n[k]+pd(k+1);
		return n[k];
	}
	else if(s1[k]==1){
		n[k]=n[k]+1;
		s1[k]=0;
		if(s1[k+1]==1){n[k]=n[k]+pd(k+1); return n[k];}
		else return n[k];
	}
	else if(s2[k]==1){
		n[k]=n[k]+1;
		s2[k]=0;
		if(s2[k+1]==1){n[k]=n[k]+pd(k+1); return n[k];}
		else return n[k];
	}
	else return n[k];
}

int main(){
	int c,ans=0;
	cin>>c;
	for(int i=1;i<=c;i++) cin>>s1[i];
	for(int i=1;i<=c;i++) cin>>s2[i];
	for(int i=1;i<=c;i++){
		if(s1[i]==1){
			if(pd(i)>=6 || pd[i]==0) ans=ans+pd(i);
			else ans=ans+pd(i)+2;
			continue;
		}
		if(s2[i]==1){
			if(pd(i)>=6 || pd[i]==0) ans=ans+pd(i);
			else ans=ans+pd(i)+2;
		}
	}
	cout<<ans;
	return 0;
}
