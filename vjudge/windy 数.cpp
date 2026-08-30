#include <iostream>
#include <algorithm>
using namespace std;

int digit(stirng s, int x = 0, bool ok = false, int ban = 0, bool ban09 = 0){
	if (x == s.size()) return 1;
	if (ok){
		return digit(s, x+1, 1, 2, 0) * (6 - ban)
	} else {
		return ;
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << digit(b) - digit(a-1) << '\n';
	return 0;
}



