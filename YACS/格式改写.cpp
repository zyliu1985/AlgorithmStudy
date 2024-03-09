#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int c = 0;
	int m = 0;
	for(int i = 0; i< s.length(); i++) {
		if(s[i] > 'Z') m++;
		else c++;
	}
	
	cout << min(c, m);
	return 0;
}