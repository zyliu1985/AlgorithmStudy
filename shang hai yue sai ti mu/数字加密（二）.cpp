#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < 4; i++) s[i] = char(((s[i]-'0')+5) % 10 + '0');
	swap(s[0], s[3]);
	swap(s[1], s[2]);
	cout << s << endl;
	return 0;
}