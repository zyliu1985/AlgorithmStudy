#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x){
	if(parent[x]!=x){
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
int g,p;
int main(){
	cin>>g>>p;
	parent.resize(g+2);
	for(int i=1;i<=g+1;++i){
		parent[i]=i;
	}
	int cnt=0;
	for(int i=0;i<p;++i){
		int a;
		cin>>a;
		int av=find(a);
		if(av==0){
			break;
		}
		cnt++;
		parent[av]=find(av-1);
	}
	cout<<cnt<<'\n';
	return 0;
}
