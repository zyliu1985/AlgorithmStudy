#include <iostream>
using namespace std;

bool hui(string s){
	for (int i = 0; i < s.size(); i++)
		if (s[i] != s[s.size()-1-i])
			return false;
	return true;
}
int main(){
	string s;
	cin >> s;
	int len = s.size();
	for (int i = len-1; i >= 0; i--){
		if (s[i] != '0') break;
		s = s.substr(0, len-1);
		len = s.size();
	}
	if (hui(s)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
10 20
100 89 100 72 39 50 74 50 50 1
1 2 1
1 3 1
1 4 1
2 5 1
1 5 1
3 5 1
2 3 1
2 4 1
3 4 1
4 5 1
1 6 1
6 7 1
1 8 1
6 9 1
9 10 1
1 7 1
6 8 1
8 9 1
1 10 1
7 8 1
Ð¡ºï±à³Ì£¨7155823023100578£©