#include<bits/stdc++.h>
using namespace std;
struct p{
	int num=0,sum=0;
}t[5];

bool cmp(p x,p y){
	return x.sum>y.sum;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			t[j].num=j;
			char c;
			cin>>c;
			if(c=='Y'){
				t[j].sum++;
			}
		}
	}
	sort(t+1,t+6,cmp);
	for(int i=1;i<=5;i++){
		if(t[i].sum==t[1].sum){
			if(i!=1){
				cout<<",";
			}
			cout<<t[i].num;
		}
	}
	return 0;
}

