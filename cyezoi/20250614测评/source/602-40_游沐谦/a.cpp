#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s[100005];
struct node {
	int tim,id;
}t[5];

bool cmp(node x,node y) {
	if(x.tim != y.tim) return x.tim > y.tim;
	else return x.id < y.id;
}


signed main() {
	cin >> n;
	for(int i = 0; i < 5; i++) t[i].id = i + 1;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		for(int j = 0; j < 5; j++) {
			if(s[i][j] == 'Y') t[j].tim++;
		}
	}
	sort(t,t+5,cmp);
	for(int i = 0; i < 5; i++) {
		if(t[i].tim < t[i-1].tim) break;
		if(i != 0) cout << ','; 
		cout << t[i].id;
	}
	
}



