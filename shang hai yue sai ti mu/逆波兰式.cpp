#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

stack<int> st;
string s;

int main(){
	getline(cin, s);
	char t;
	for (int i = 0; i < s.size(); i++){
		t = s[i];
		if (t == ' ') continue;
		if (t >= '0' && t <= '9') st.push(int(t-'0'));
		else{
			int a, b;
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			if (t == '+') st.push((b+a)%10);
			if (t == '-') st.push((b-a+10)%10);
			if (t == '*') st.push((b*a)%10);
		}
	}
	cout << st.top()%10 << endl;
	return 0;
}