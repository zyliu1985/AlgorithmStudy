#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	int n;
	cin >> n;
	if (s.size() >= n) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}



