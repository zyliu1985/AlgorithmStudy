#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
string s;

int main(){
	cin >> s;
	vector<char>::iterator pos = v.begin();
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '[') pos = v.begin();
		else if (s[i] == ']') pos = v.end();
		else{
			pos = v.insert(pos, s[i]);
			pos++;
		}
	}
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	return 0;
}