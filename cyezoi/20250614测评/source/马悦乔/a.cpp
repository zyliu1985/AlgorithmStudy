#include<bits/stdc++.h>
using namespace std;
struct date {
	int day;
	int num;
} a[5];
bool cmp(date a,date b) {
	if(a.num!=b.num)return a.num>b.num;
	else return a.day<b.day;
}
int main() {
	int n;
	cin>>n;
	for(int i=0; i<5; i++) {
		a[i].day=i+1;
		a[i].num=0;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<5; j++) {
			char c;
			cin>>c;
			if(c=='Y') {
				a[j].num++;
			}
		}
	}
	sort(a,a+5,cmp);
	cout<<a[0].day;
	for(int i=1; i<5; i++) {
		if(a[i].num==a[i-1].num)cout<<","<<a[i].day;
		else break;
	}
	return 0;
}
