#include<bits/stdc++.h>
using namespace std;
int planes[100005],n,m;
bool visited[100005]; 
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>planes[i];
	}
	for(int p=0;;p++){
		bool flag=0;
		while(planes[p]--){
			if(visited[planes[p]]==0 and p<=m){
				visited[planes[p]]=1;
				flag=1;
				
				break;
			}
		}
		if(flag==0 || p==m-1){
			cout<<p<<endl;
			break;
		}
	}
	return 0;
}
