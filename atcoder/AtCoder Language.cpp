#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	if (s == "red") cout << "SSS\n";
	else if (s == "green") cout << "MMM\n";
	else if (s == "blue") cout << "FFF\n";
	else cout << "Unknown\n";
	return 0;
}

