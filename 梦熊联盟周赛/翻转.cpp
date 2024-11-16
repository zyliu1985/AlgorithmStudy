#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("reverse.in", "r", stdin);
	freopen("reverse.in", "w", stdout);
	int n;
	string s;
	bool latest = true;
	int prefix = 0;
	int count = 0;
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			if(s[i] == '0') {
				prefix = 1;
				latest = false;
			} else {
				latest = true;
			}
			count++;
			continue;
		}
		if(s[i] == '1') {
			if(!latest) {
				count ++;
				latest = true;
			}
		} else {
			if(latest) {
				count++;
				latest = false;
			}
		}
	}
	
	cout << count - 1 - prefix << endl;
	
	return 0;
}
