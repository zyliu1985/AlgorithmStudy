#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,ans;
	cin>>c;
	int a[200001],b[200001];
	for(int i=0;i<c;i++)
		cin>>a[i];
	for(int i=0;i<c;i++)
		cin>>b[i];
	for(int i=0;i<c;i++){
		if(i%2==0){
			if(a[i]==1){
				ans+=3;
		        if(a[i-1]==1)
				    ans--;
				if(a[i+1]==1)
				    ans--;
			    if(b[i]==1)
				    ans--;
		    }
			if(b[i]==1){
				ans+=3;
			    if(b[i-1]==1)
				    ans--;
				if(b[i+1]==1)
					ans--;
				if(a[i]==1)
				    ans--;
		    }
		}
		if(i%2==1){
			if(a[i]==1){
				ans+=3;
			    if(a[i-1]==1)
				    ans--;
				if(a[i+1]==1)
				    ans--;
		    }
			if(b[i]==1){
				ans+=3;
			    if(b[i-1]==1)
				    ans--;
				if(b[i+1]==1)
				    ans--;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
