#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	long long sum = 0, ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '0') ans += sum;
		else sum++;
	cout << ans << endl;
	return 0;
}