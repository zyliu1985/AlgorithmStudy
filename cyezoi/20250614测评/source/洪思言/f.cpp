#include<bits/stdc++.h>
using namespace std;

	int n,a[4000],m,b[200],c[4200],sum = 0;
	bool cmp(int a,int b){
		return a > b;
	}
	
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = a[i];
	}
	cin >> m;
	for (int i = 1;i <= m;i++){
		cin >> b[i];
		c[n + i] = b[i];
	}
	sort(c + 1,c + n + m + 1,cmp);
	int p;
	if ((n + m) % 2 == 1)
		p = (n + m) / 2 + 1;
	else
		p = (n + m) / 2;
	for (int i = 1;i <= p;i++){
		sum += c[i];
	}
	cout << sum;
	return 0;
}

