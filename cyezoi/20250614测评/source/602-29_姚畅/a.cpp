#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,y;
}a[10];
bool cmp(node u,node v){
	return (u.x==v.x?u.y<v.y:u.x>v.x);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char tmp;
			cin >> tmp;
			if(tmp=='Y')a[j].x++;
			a[j].y=j;
		}
	}
	sort(a+1,a+6,cmp);
	int m=a[1].x;
	for(int i=1;i<=5;i++){
		if(a[i].x==m){
			cout <<a[i].y;
			if(i<5&&a[i+1].x==m)cout << ',';
		}
	}
	
	return 0;
}
