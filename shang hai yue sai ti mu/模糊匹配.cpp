#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string t;
		cin >> t;
		if (s.size() != t.size()) continue;
		bool flag = true;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == '?') continue;
			if (s[j] != t[j]){
				flag = false;
				break;
			}
		}
		cnt += flag;
	}
	cout << cnt << endl;
	return 0;
}