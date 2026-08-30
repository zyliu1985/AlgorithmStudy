#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '#'){
			flag = true;
			cout << '#';
		} else {
			if (flag) cout << 'o', flag = false;
			else cout << '.';
		}
	return 0;
}



