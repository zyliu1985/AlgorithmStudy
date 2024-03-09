#include <iostream>
using namespace std;

int main(){
	string s, ans, t;
	cin >> s;
	t += s[0]-'A'+'a';
	for (int i = 1; i < s.size(); i++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			ans += t+'_';
			t = s[i]-'A'+'a';
		} else t += s[i];
	}
	ans += t;
	cout << ans << endl;
	return 0;
}