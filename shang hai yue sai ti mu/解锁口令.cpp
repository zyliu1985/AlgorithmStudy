#include <iostream>
using namespace std;

int main(){
	string s, t;
	cin >> s;
	int ans = 0, cnt = 0, x = 1;
	do{
		cnt++;
		cin >> t;
		if (cnt > 3){
			ans += x;
			x *= 2;
		}
		if (cnt == 10 && t != s){
			cout << "Locked" << endl;
			return 0;
		}
	} while(t != s);
	cout << ans << endl;
	return 0;
}