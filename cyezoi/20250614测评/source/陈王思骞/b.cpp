#include<bits/stdc++.h>
using namespace std;
int main(){
	int c;
	cin>>c;
	int p[2*c+10],sum;
	for(int i=1;i<=2*c;i++){
		cin>>p[i];
		if(p[i]==1)
			sum+=3;
	}
	for(int i=1;i<=c;i++){
		if(p[i]==1&&p[c+i]==1)
			sum-=2;
		if(p[i]==1&&p[i+1]==1)
			sum-=2;
	}
	cout<<sum;
	return 0;
}
