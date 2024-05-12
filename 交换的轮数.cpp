#include <iostream>
using namespace std;

bool check(string x){
	bool flag = false;
	for (int i = 0; i < x.size(); i++)
		if (x[i] != '0' + flag)
			if (!flag) flag = true;
			else return true;
	return false;
}
int main(){
	string s, t;
	long long ans = 0;
	cin >> s;
	while (check(s)){
		ans++;
		t = s;
		for (int i = 1; i < s.size(); i++)
			if (s[i] == '0' && s[i-1] == '1')
				swap(t[i], t[i-1]);
		s = t;
	}
	cout << ans << endl;
	return 0;
}