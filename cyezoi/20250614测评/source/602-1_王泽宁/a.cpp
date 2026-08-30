#include<bits/stdc++.h>
using namespace std;
int n;
struct tim{
	int num,id;
} a[10];
bool cmp(tim a,tim b) {
	if(a.num==b.num) return a.id<b.id;
	return a.num>b.num;
}
int main() {
	cin>>n;
	for(int i=1;i<=5;i++) a[i].id=i;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=5;j++) {
			char c;
			cin>>c;
			if(c=='Y') a[j].num++;
		}
	}
	sort(a+1,a+5+1,cmp);
	cout<<a[1].id;
	for(int i=2;i<=5;i++) {
		if(a[i].num==a[1].num) 
			cout<<','<<a[i].id;
	}
	return 0;
}
