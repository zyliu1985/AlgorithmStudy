#include <iostream>
#include <stack>
using namespace std;

stack<char> a;
int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(')  a.push(s[i]);
		if (s[i] == ')'){
			if (!a.empty()) a.pop();
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (a.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;	
}
