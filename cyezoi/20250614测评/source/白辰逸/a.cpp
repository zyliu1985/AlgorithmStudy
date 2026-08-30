#include<bits/stdc++.h>
using namespace std;
struct p{
	long long id,num;
}a[100010]={0};
bool cmp(p a,p b){
	return a.num>b.num;
}
int main(){
	long long n;
	cin>>n;
	char c[n+1];
	long long cnt=1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=5;i++){
			a[i].id=i;
			cin>>c[i];
			if(c[i]=='Y')
				a[i].num++;
		}
	}
	sort(a+1,a+5+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<a[i].id;
		if(a[i+1].num==a[i].num)
			cout<<',';
		else
			return 0;
	}
return 0;
}
