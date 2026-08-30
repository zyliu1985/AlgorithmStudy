//#  optimize(3);
#include <bits/stdc++.h>
using namespace std;
int n;
int a[6];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int i = 1;i <= 5;i++){
			char x;
			cin >> x;
			if(x == 'Y') a[i]++;
		}
	}
	
	int maxn = 0;
	for(int i = 1;i <= 5;i++)
		maxn = max(maxn,a[i]);
	//printf("%d\n\n",maxn);
	string s = "";
	for(int i = 1;i <= 5;i++){
		if(maxn == a[i]){
			s = s+","+char(i+'0');
		}
	}
	for(int i = 1;i < s.length();i++)
		cout << s[i];
	
	return 0;
}
