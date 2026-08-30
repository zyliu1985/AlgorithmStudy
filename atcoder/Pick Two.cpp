#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int last = 0;
	char c;
	for (int i = 1; cin >> c; i++){
		if (c == '#'){
			if (last) cout << last << ',' << i << '\n', last = 0;
			else last = i;
		}
	}
	return 0;
}



