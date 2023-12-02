#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'z') cout << char((s[i]-'a'+3)%26+'a');
		else cout << char((s[i]-'A'+3)%26+'A');
	}
	return 0;
}