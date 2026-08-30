#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n < 3) cout << "No\n";
	else if (s.substr(n-3, 3) == "tea") cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

