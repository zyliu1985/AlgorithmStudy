#include <iostream>
using namespace std;

int num[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++){
			char c;
			cin >> c;
			if (c == 'Y') num[j]++;
		}
	int maxn = 0, last;
	for (int j = 0; j < 5; j++){
		maxn = max(maxn, num[j]);
		if (num[j] == maxn) last = j;
	}
	for (int j = 0; j < 5; j++){
		if (num[j] == maxn){
			cout << j+1;
			if (j != last) cout << ',';
		}
	}
	return 0;
}
