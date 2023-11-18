#include <iostream>
using namespace std;

int main(){
	string s, t;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> s >> t;
		bool flag1 = true;
		for (int j = 0; j < t.size(); j++){
			if (t[j] == s[0]){
				int cur = (j+1) % t.size();
				bool flag2 = true;
				for (int k = 1; k < s.size(); k++){
					if (s[k] != t[cur]){
						flag2 = false;
						break;
					}
					cur++;
					cur %= t.size();
				}
				if (flag2){
					flag1 = false;
					cout << "Yes" << endl;
					break;
				}
			}
		}
		if (flag1) cout << "No" << endl;
	}
	return 0;
}