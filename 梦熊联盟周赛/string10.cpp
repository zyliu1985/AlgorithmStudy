#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 998244353;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){
		for (int j = max(i - 2, 0); j < min(i + 2, n); j++)
			if (s[i] == s[j] && i != j){
				cout << 0 << endl; return 0;
			}
				
	}
	cout << 1 << endl;
	return 0;
}
