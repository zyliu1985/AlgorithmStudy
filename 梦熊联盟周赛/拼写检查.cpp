#include <iostream>
using namespace std;

int main(){
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	string s, ans = "NOANSWER";
	cin >> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string a;
		cin >> a;
		if (a == s){
			cout << a << endl;
			return 0;
		} 
		for (int j = 0; j < a.size(); j++){
//			cout << "ÉÙ£º" << a.substr(0, j) + a.substr(j + 1) << ' ' << s << endl;
			if (a.substr(0, j) + a.substr(j + 1) == s)
				if (ans == "NOANSWER")
					ans = a;
		}
		for (int j = 0; j < s.size(); j++){
//			cout << "¶à£º" << a << ' ' << s.substr(0, j) + s.substr(j + 1) << endl;
			if (a == s.substr(0, j) + s.substr(j + 1))
				if (ans == "NOANSWER")
					ans = a;
		}
		if (a.size() == s.size()){
			for (int j = 0; j < a.size(); j++){
//				cout << "¸Ä£º" << a.substr(0, j) + a.substr(j + 1) << ' ' << s.substr(0, j) + s.substr(j + 1) << endl;
				if (a.substr(0, j) + a.substr(j + 1) == s.substr(0, j) + s.substr(j + 1))
					if (ans == "NOANSWER")
						ans = a;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
