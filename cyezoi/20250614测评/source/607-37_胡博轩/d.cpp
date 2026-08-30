#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g,p,x,fail[100009],chng[100009];
bool used[100009];
int test(int x){
	int now=x,ccnt=0;
	for(;now;now=fail[now]){
		if(!used[now]){
			used[now]=1;
			break;
		}
		chng[++ccnt]=now;
	}
	for(int i=1;i<=ccnt;i++) fail[chng[i]]=now;
	return now;
}
int main(){
	cin>>g>>p;
	for(int i=1;i<=g;i++){
		fail[i]=i-1;
	}
	for(int i=1;i<=p;i++){
		cin>>x;
		if(!test(x)){
			cout<<i-1;
			return 0;
		}
	}
	cout<<p;
	return 0;
}

