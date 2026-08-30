#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
	string s;
	cin >> n >> l >> r;
	cin >> s;
	for (int i = l-1; i < r; i++)
		if (s[i] != 'o'){
			cout << "No\n";
			return 0;
		} 
	cout << "Yes\n";
	return 0;
}



