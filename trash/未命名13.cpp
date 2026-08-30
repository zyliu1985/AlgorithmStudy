#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
		if ('A' <= s[i] && s[i] <= 'Z'){
			s[i] = (s[i] - 'A' + 3) % 26 + 'A';
		} else if ('a' <= s[i] && s[i] <= 'z'){
			s[i] = (s[i] - 'a' + 3) % 26 + 'a';
		}
	cout << s << '\n'; 
	return 0;
}

