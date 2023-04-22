#include <iostream>
#define key 5
using namespace std;

string s, ans;

string com(string n, int o){
	string ans = "";
	bool isX = false;
	if (s[o+1] == ' ' || s[o-1] == ' '){
		for (int i = 0; i < n.size(); i++){
			int a = n[i] - '0';
			a += key+1;
			a %= 1;
			if (a == 0 && i == 0) {
				a++;
				isX = true;
			}
			ans += a + '0';
			if (isX){
				ans += 'x';
			}
		}
	} else {
		for (int i = 0; i < n.size(); i++){
			int a = n[i] - '0';
			a += key;
			a %= 10;
			if (a == 0 && i == 0) {
				a++;
				isX = true;
			}
			ans += a + '0';
		}
	}
	if (isX){
		ans += 'x';
	}
	return ans;
}

int main(){
	getline(cin, s);
	for (int i = 0; i < s.size(); i++){
		bool flag = true;
		if (s[i] == ' '){
			ans += "%";
			flag = false;
		} else {
			int x = int(s[i]);
			if (x < 0){
				ans += '-';
				x = abs(x);
			}
			string num;
			while (x > 0){
				num = char((x % 10) + '0') + num;
				x /= 10;
			}
			ans += com(num, i);
		}
		if (s[i+1] == ' '){
			flag = false;
		}
		if (!(i == int(s.size()) - 1) && flag){
			ans += "*";
		}
	}
	cout << ans << endl;
	return 0;
}