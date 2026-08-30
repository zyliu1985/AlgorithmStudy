#include <iostream>
#include <algorithm>
using namespace std;

void solve(string x, string s){
	if (s == "rab"){
		for (int i = 0; i < x.size(); i++)
			if (x[i] >= 'a' && x[i] <= 'z'){
				cout << "CORRECT (maybe)\n";
				return;
			}
		cout << "WRONG!\n";
		return;
	} else if (s == "gema"){
		if (x.size() < 4){
			cout << "WRONG!\n";
			return;
		} else {
			int cur = -1;
			for (int i = 1; i <= 4; i++)
				if (x[x.size() - i] == s[3]){
					cur = x.size() - i;
					break;
				} else if (x[x.size() - i] >= 'a' && x[x.size() - i] <= 'z'){
					cout << "WRONG!\n";
					return;
				}
			if (cur < 3){
				cout << "WRONG!\n";
				return;
			} else if (x[cur-1] == s[2] && x[cur-2] == s[1] && x[cur-3] == s[0]){
				cout << "CORRECT (maybe)\n";
				return;
			} else {
				cout << "WRONG!\n";
				return;
			}
		}
	}
	if (x.size() < 3){
		cout << "WRONG!\n";
		return;
	} else {
		int cur = -1;
		for (int i = 1; i <= 4; i++)
			if (x[x.size() - i] == s[2]){
				cur = x.size() - i;
				break;
			} else if (x[x.size() - i] >= 'a' && x[x.size() - i] <= 'z'){
				cout << "WRONG!\n";
				return;
			}
		if (cur < 2){
			cout << "WRONG!\n";
			return;
		} else if (x[cur-1] == s[1] && x[cur-2] == s[0]){
			cout << "CORRECT (maybe)\n";
			return;
		} else {
			cout << "WRONG!\n";
			return;
		}
	}
}
int main(){
	freopen("dialogue.in", "r", stdin);
	freopen("dialogue.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    string name, x;
    while (cin >> name){
    	getchar();
    	getline(cin, x);
    	for (int i = 0; i < x.size(); i++)
    		if (x[i] >= 'A' && x[i] <= 'Z')
    			x[i] = x[i] - 'A' + 'a';
//    	cout << name << ' ' << x << '\n';
    	if (name == "digi"){
    		solve(x, "nyo");
		} else if (name == "petit"){
			solve(x, "nyu");
		} else if (name == "rabi"){
			solve(x, "rab");
		} else if (name == "gema"){
			solve(x, "gema");
		} else if (name == "piyo"){
			solve(x, "pyo");
		}
	}
	return 0;
}



