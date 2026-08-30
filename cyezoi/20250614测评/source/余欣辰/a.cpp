# include <bits/stdc++.h>
using namespace std;
int n,a[20],b[20],k=0;
string s;
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> s;
		for (int j=0;j<s.length();j++){
			if (s[j]=='Y'){a[j+1]++;}
		}
	}
	int mx=0;
	for (int i=1;i<=5;i++){mx=max(a[i],mx);}
	for (int i=1;i<=5;i++){
		if (a[i]==mx){b[++k]=i;}
	}
	cout << b[1];
	for (int i=2;i<=k;i++){cout << ',' << b[i];}
	return 0;
}
