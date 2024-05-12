#include <iostream>
#include <map>
using namespace std;

int main(){
	string s;
	cin >> s;
	s = s.substr(1, s.size() - 1);
	cout << s << endl;
	return 0;
}