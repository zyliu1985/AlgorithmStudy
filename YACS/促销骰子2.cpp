#include <iostream>
#include <cmath>
using namespace std;

int main(){
//	int c, cnt = 0;
//	while (cin >> c){
//		if (c == 6) cnt++;
//	}
//	if (cnt == 0) cout << 0 << endl;
//	if (cnt == 1) cout << 10 << endl;
//	if (cnt == 2) cout << 100 << endl;
//	if (cnt == 3) cout << 1000 << endl;


//	int c = 0, cnt = 0, t = 1;
//	do {
//		cin >> c;
//		if (c == 6) cnt++;
//		t++;
//	} while (c == 6 && t < 4);
//	if (cnt == 0) cout << 0 << endl;
//	if (cnt == 1) cout << 10 << endl;
//	if (cnt == 2) cout << 100 << endl;
//	if (cnt == 3) cout << 1000 << endl;
	string s;
	int cnt = 0, c = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++){
		if (s[i] == ' ') continue;
		int x = int(s[i]-'0');
		if (s[i+1] != ' ') c += x*10;
		else {
			c += x;
			if (c == 6) cnt++;
			c = 0;
		}
	}
	if (cnt == 0) cout << 0 << endl;
	if (cnt == 1) cout << 10 << endl;
	if (cnt == 2) cout << 100 << endl;
	if (cnt == 3) cout << 1000 << endl;
	return 0;
}