#include <iostream>
#include <stack>
using namespace std;

stack<int> st; // 1表示"("，2表示"["
string s;

int main(){
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++){
		if (s[i] == '(') st.push(1);
		else if (s[i] == '[') st.push(2);
		else if (s[i] == ')'){
			if (!st.empty() && st.top() == 1) st.pop();
			else{
				cout << "Unbalanced" << endl;
				return 0;
			}
		} else {
			if (!st.empty() && st.top() == 2) st.pop();
			else{
				cout << "Unbalanced" << endl;
				return 0;
			}
		}
	}
	if (st.empty()) cout << "Balanced" << endl;
	else cout << "Unbalanced" << endl;
	return 0;
}