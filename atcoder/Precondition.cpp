#include <iostream>
#include <algorithm>
using namespace std;

bool have[135];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++)
		have[t[i]] = true;
	for (int i = 1; i < s.size(); i++)
		if ('A' <= s[i] && s[i] <= 'Z' && !have[s[i-1]]){
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
	return 0;
}



