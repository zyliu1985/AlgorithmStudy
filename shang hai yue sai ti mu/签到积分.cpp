#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int cnt = 0, ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'Y') ans += min(++cnt, 5);
		else cnt = 0;
	}
	cout << ans << endl;
	return 0;
}